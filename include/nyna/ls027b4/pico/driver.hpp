#pragma once

#include <stdint.h>
#include <string.h>

#include "pico/stdlib.h"
#include "hardware/spi.h"

#include "nyna/graphics/graphics.hpp"

#include "nyna/ls027b4/ls027b4.hpp"

namespace nyna::ls027b4::pico {

using namespace nyna::graphics;

class Driver {
public:
    static constexpr int FRAME_RATE_MIN_MS = 50; // fSCS: 1 - 20Hz
    static constexpr int COM_TOGGLE_PERIOD_MS = 200; // fEXTCOMIN: 1Hz - 20Hz
private:
    bool _com_state = false;
    uint64_t _t_next_com_toggle = 0;
    uint64_t _t_next_pixel_trans = 0;
    bool _buff_changed = false;
    Bitmap _buff;
    uint8_t *_line_buff;
public:
    spi_inst_t * const spi;
    const int pin_scs;
    const int pin_disp;
    const int pin_extcomin;
    const bool use_extcomin;

    Driver(spi_inst_t *spi, int pin_scs, int pin_disp, int pin_extcomin) :
        _buff(SCREEN_WIDTH, SCREEN_HEIGHT, Bitmap::FLAG_FORMAT_1BPP),
        _line_buff(new uint8_t[_buff.stride]),
        spi(spi), 
        pin_scs(pin_scs), 
        pin_disp(pin_disp), 
        pin_extcomin(pin_extcomin), 
        use_extcomin(pin_extcomin >= 0)
    { }

    ~Driver() {
        delete[] _line_buff;
    }

    void init() {
        gpio_init(pin_scs);
        gpio_init(pin_disp);
        gpio_set_dir(pin_scs, GPIO_OUT);
        gpio_set_dir(pin_disp, GPIO_OUT);
        gpio_put(pin_scs, 0);
        gpio_put(pin_disp, 0);
        if (use_extcomin) {
            gpio_init(pin_extcomin);
            gpio_set_dir(pin_extcomin, GPIO_OUT);
            gpio_put(pin_extcomin, 0);
        }
        uint64_t t_now = time_us_64();
        _t_next_com_toggle = t_now + COM_TOGGLE_PERIOD_MS * 1000;
        _t_next_pixel_trans = t_now;
    }

    void disp_on() { gpio_put(pin_disp, 1); }
    void disp_off() { gpio_put(pin_disp, 0); }

    static void invertEndian(uint8_t *dst, const uint8_t *src, int size) {
        for (int i = 0; i < size; i++) {
            uint8_t b = src[i];
            dst[i] =
                ((b << 7) & 0x80) |
                ((b << 5) & 0x40) |
                ((b << 3) & 0x20) |
                ((b << 1) & 0x10) |
                ((b >> 1) & 0x08) |
                ((b >> 3) & 0x04) |
                ((b >> 5) & 0x02) |
                ((b >> 7) & 0x01);
        }
    }

    void write(Bitmap& src) {
        // Detect image change
        int bytesPerLine = Bitmap::calcStride(_buff.flags, NYNA_MIN(src.width, _buff.width));
        int height = NYNA_MIN(src.height, _buff.height);
        const uint8_t *srcPtr = src.data;
        uint8_t *dstPtr = _buff.data;
        for (int y = 0; y < height; y++) {
            bool line_changed = false;
            for (int i = 0; i < bytesPerLine; i++) {
                if (srcPtr[i] != dstPtr[i]) {
                    line_changed = true;
                    break;
                }
            }
            if (line_changed) {
                memcpy(dstPtr, srcPtr, bytesPerLine);
                _buff_changed = true;
            }
            srcPtr += src.stride;
            dstPtr += _buff.stride;
        }
    }

    void service() {
        uint64_t t_now = time_us_64();
        uint8_t spi_byte;

        // Keep max frame rate
        if (t_now <= _t_next_pixel_trans) {
            return;
        }
        _t_next_pixel_trans = t_now + FRAME_RATE_MIN_MS * 1000;

        // toggle COM flag for EXTCOMIN = L
        bool com_toggled = t_now >= _t_next_com_toggle;
        if (com_toggled) {
            _com_state = !_com_state;
            _t_next_com_toggle = t_now + COM_TOGGLE_PERIOD_MS * 1000;
        }

        if (!com_toggled && !_buff_changed) {
            return;
        }

        // Make sure EXTCOMIN is low for next rising edge
        gpio_put(pin_extcomin, 0);

        // chip select
        gpio_put(pin_scs, 1);
        sleep_us(3); // tsSCS minimum setup time is 3 us
        
        if (use_extcomin && com_toggled) {
            // SHARP LCD must have liquid crystal cell polarity inverted at between 0.5 and 20 Hz to prevent charge built up over time
            // Period between COM inversions must be kept as equal as practical
            // When EXTMODE is HIGH, EXTCOMIN rising edge arms polarity inversion to occur on next SCS falling edge
            gpio_put(pin_extcomin, 1); // Arm COM inversion, once per full frame
            sleep_us(1); // twEXTCOMIN minimum high time is 1 us
            gpio_put(pin_extcomin, 0);
        }
            
        // mode select
        uint8_t flag_upd_mode = _buff_changed ? 1 : 0;
        uint8_t flag_vcom = _com_state ? 1 : 0;
        uint8_t flag_all_clear = 0;
        spi_byte = 
            (flag_upd_mode << 0) |  // M0
            (flag_vcom << 1) | // M1
            (flag_all_clear << 2); // M2
        invertEndian(&spi_byte, &spi_byte, 1);
        spi_write_blocking(spi, &spi_byte, 1);

        if (_buff_changed) {
            // Pixel data transfer
            uint8_t gate_line = 1;
            const uint8_t *data = _buff.data;
            for (int src_y = 0; src_y < SCREEN_HEIGHT; src_y++) {
                // line select
                invertEndian(&spi_byte, &gate_line, 1);
                spi_write_blocking(spi, &spi_byte, 1);

                // write line
                invertEndian(_line_buff, data, _buff.stride);
                spi_write_blocking(spi, _line_buff, _buff.stride);

                // dummy write
                spi_byte = 0x00;
                spi_write_blocking(spi, &spi_byte, 1);

                data += _buff.stride;
                gate_line += 1;
            }
        }

        // dummy write
        spi_byte = 0x00;
        spi_write_blocking(spi, &spi_byte, 1);

        // chip deselect
        sleep_us(1); // thSCS is minimum 1 us
        gpio_put(pin_scs, 0);
        sleep_us(1); // twSCSL is minimum 1 us

        _buff_changed = false;
    }

};

}
