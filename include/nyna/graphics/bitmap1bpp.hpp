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

    void setPixel(int x, int y, color_t c, PixelMethod method = 0) override {
        PixelOperation op = method.op;

        if (op == PixelOperation::NOP) return;
        if (!clipRect.contains(x, y)) return;

        bool white = (c != BLACK);
        if (method.srcNot) white = !white;

        switch (op) {
        case PixelOperation::OR:
        case PixelOperation::XOR:
            if (!white) return;
            break;
        case PixelOperation::AND:
            if (white) return;
            break;
        case PixelOperation::COPY:
            op = white ? PixelOperation::OR : PixelOperation::AND;
            break;
        }

        uint8_t *ptr = getPixelPointer(x, y);
        uint8_t mask = 1 << (x % 8);
        switch (op) {
        case PixelOperation::OR: *ptr |= mask; break;
        case PixelOperation::AND: *ptr &= ~mask; break;
        case PixelOperation::XOR: *ptr ^= mask; break;
        }
    }

    void fillRect(Rect rect, color_t c, PixelMethod op = 0) override {
        rect.intersectSelf(clipRect);
        if (rect.width <= 0 || rect.height <= 0) return;
        int x0 = rect.x;
        int y0 = rect.y;
        int r = rect.right();
        int b = rect.bottom();

        // todo: optimize
        for (int y = y0; y < b; y++) {
            for (int x = x0; x < r; x++) {
                setPixel(x, y, c, op);
            }
        }
    }

    int drawChar(const TinyFont &font, int dx0, int dy0, char code, color_t col, PixelMethod op = 0) override {
        const TinyFontGlyph *glyph = font.getGlyph(code);
        if (!glyph) return 0;
        if (!glyph->isBlank()) {
            op.srcNot = (col == BLACK);
            const Bitmap1bpp bmp(glyph->width, font.height, calcStride(glyph->width), (uint8_t *)(font.bitmap + glyph->offset));
            drawBitmap(dx0, dy0, bmp, op);
        }
        return glyph->width;
    }
};

}
