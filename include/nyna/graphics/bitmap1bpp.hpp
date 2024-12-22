#pragma once

#include <stdint.h>
#include <string.h>

#include "nyna/graphics/common.hpp"
#include "nyna/graphics/bitmap.hpp"

namespace nyna::graphics {

class Bitmap1bpp : public Bitmap<uint8_t> {
public:
    using base = Bitmap<uint8_t>;
    using base::fillRect;
    using base::drawBitmap;

    static int calcStride(int width) {
        return NYNA_CEIL_DIV(width, 8);
    }

    uint8_t * const data;

    Bitmap1bpp(int w, int h, int stride, void *data, flag_t flags = 0) :
        base(w, h, stride, flags),
        data((uint8_t*)data)
    { }

    Bitmap1bpp(int w, int h, flag_t flags = 0) :
        base(w, h, calcStride(w), flags | FLAG_AUTO_FREE),
        data(new uint8_t[stride * h])
    { }

    ~Bitmap1bpp() {
        if (flags & FLAG_AUTO_FREE) {
            delete[] data;
        }
    }

    uint32_t size() const override { return stride * height; }

    void clear(color_t color) override {
        memset(data, color == BLACK ? 0x00 : 0xff, size());
    }

    uint8_t *getPixelPointer(int x, int y) const override {
        return data + (stride * y) + (x / 8);
    }

    color_t getPixel(int x, int y) const override {
        uint8_t mask = 1 << (x % 8);
        return (*getPixelPointer(x, y) & mask) ? WHITE : BLACK;
    }

    void setPixel(int x, int y, color_t col, PixelOp op = PixelOp::DEFAULT) override {
        if (!clipRect.contains(x, y)) return;
        if ((op & PixelOp::SRC_PATTERN) != PixelOp::EMPTY && ((x + y) & 1) == 0) return;

        bool white = (col != BLACK);
        if ((op & PixelOp::SRC_NOT) != PixelOp::EMPTY) {
            white = !white;
        }

        PixelOp gate = op & PixelOp::GATE_MASK;
        switch (gate) {
        case PixelOp::GATE_OR:
        case PixelOp::GATE_XOR:
            if (!white) return;
            break;
        case PixelOp::GATE_AND:
            if (white) return;
            break;
        case PixelOp::GATE_COPY:
            gate = white ? PixelOp::GATE_OR : PixelOp::GATE_AND;
            break;
        }

        uint8_t *ptr = getPixelPointer(x, y);
        uint8_t mask = 1 << (x % 8);
        switch (gate) {
        case PixelOp::GATE_OR: *ptr |= mask; break;
        case PixelOp::GATE_AND: *ptr &= ~mask; break;
        case PixelOp::GATE_XOR: *ptr ^= mask; break;
        }
    }

    void fillRect(Rect rect, color_t col, PixelOp op = PixelOp::DEFAULT) override {
        rect.intersectSelf(clipRect);
        if (rect.width <= 0 || rect.height <= 0) return;
        int x0 = rect.x;
        int y0 = rect.y;
        int r = rect.right();
        int b = rect.bottom();

        // todo: optimize
        for (int y = y0; y < b; y++) {
            for (int x = x0; x < r; x++) {
                setPixel(x, y, col, op);
            }
        }
    }

    int drawChar(const TinyFont &font, int dx0, int dy0, char code, color_t col, PixelOp op = PixelOp::DEFAULT) override {
        const TinyFontGlyph *glyph = font.getGlyph(code);
        if (!glyph) return 0;
        if (!glyph->isBlank()) {
            if (col == BLACK) op |= PixelOp::SRC_NOT;
            const Bitmap1bpp bmp(glyph->width, font.height, calcStride(glyph->width), (uint8_t *)(font.bitmap + glyph->offset));
            drawBitmap(dx0, dy0, bmp, bmp.getBounds(), op);
        }
        return glyph->width;
    }
};

}
