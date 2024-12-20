#pragma once

#include <stdint.h>
#include <string.h>

#include "nyna/graphics/common.hpp"
#include "nyna/graphics/bitmap.hpp"

namespace nyna::graphics {

class Bitmap1bpp : public Bitmap<uint8_t> {
public:
    static int calcStride(int width) {
        return NYNA_CEIL_DIV(width, 8);
    }

    uint8_t * const data;

    Bitmap1bpp(int w, int h, int stride, void *data, flag_t flags = 0) :
        Bitmap(w, h, stride, flags),
        data((uint8_t*)data)
    { }

    Bitmap1bpp(int w, int h, flag_t flags = 0) :
        Bitmap(w, h, calcStride(w), flags | FLAG_AUTO_FREE),
        data(new uint8_t[stride * h])
    { }

    ~Bitmap1bpp() {
        if (flags & FLAG_AUTO_FREE) {
            delete[] data;
        }
    }

    uint32_t size() const { return stride * height; }

    Rect getBounds() const { return Rect(0, 0, width, height); }

    void setClipRect(Rect bounds) {
        bounds.intersectSelf(getBounds());
        clipRect = bounds;
    }

    void setClipRect(int x, int y, int w, int h) {
        setClipRect(Rect(x, y, w, h));
    }

    void clearClipRect() {
        setClipRect(getBounds());
    }

    void clear(color_t color) override {
        memset(data, color == BLACK ? 0x00 : 0xff, size());
    }

    uint8_t *getPixelPointer(int x, int y) const override {
        return data + (stride * y) + (x / 8);
    }

    color_t getPixel(int x, int y) const override {
        return *getPixelPointer(x, y) ? WHITE : BLACK;
    }

    void setPixel(int x, int y, color_t c, PixelOp op = PixelOp::OVERWRITE) override {
        if (op == PixelOp::NOP) return;
        if (!clipRect.contains(x, y)) return;
        uint8_t mask = 1 << (x % 8);

        if (op == PixelOp::OVERWRITE) {
            op = (c == BLACK) ? PixelOp::AND : PixelOp::OR;
        }

        uint8_t *ptr = (uint8_t*)getPixelPointer(x, y);
        switch (op) {
        case PixelOp::OR: *ptr |= mask; break;
        case PixelOp::AND: *ptr &= ~mask; break;
        case PixelOp::XOR: *ptr ^= mask; break;
        }
    }

    void fillRect(Rect rect, color_t c, PixelOp op = PixelOp::OVERWRITE) override {
        rect.intersectSelf(clipRect);
        if (rect.w <= 0 || rect.h <= 0) return;
        int x0 = rect.x;
        int y0 = rect.y;
        int r = rect.r();
        int b = rect.b();

        // todo: optimize
        for (int y = y0; y < b; y++) {
            for (int x = x0; x < r; x++) {
                setPixel(x, y, c, op);
            }
        }
    }

    int drawChar(const TinyFont &font, int dx0, int dy0, char code, color_t col, PixelOp op = PixelOp::OVERWRITE) override {
        const TinyFontGlyph *glyph = font.getGlyph(code);
        if (!glyph) return 0;
        if (!glyph->isBlank()) {
            const Bitmap1bpp bmp(glyph->width, font.height, calcStride(glyph->width), (uint8_t *)(font.bitmap + glyph->offset));
            drawBitmap(dx0, dy0, bmp, op);
        }
        return glyph->width;
    }
};

}
