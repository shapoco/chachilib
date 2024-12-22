#pragma once

#include <stdint.h>
#include <string.h>

#include "nyna/fixed12.hpp"
#include "nyna/graphics/common.hpp"
#include "nyna/graphics/tiny_font.hpp"

namespace nyna::graphics {

template<typename BufferType>
class Bitmap {
public:
    using flag_t = uint8_t;

    static constexpr flag_t FLAG_AUTO_FREE = 1 << 0;

    const uint16_t width;
    const uint16_t height;
    const uint16_t stride;
    const flag_t flags;

    Rect clipRect;

    Bitmap(int w, int h, int stride, flag_t flags = 0) :
        width(w),
        height(h),
        stride(stride),
        flags(flags),
        clipRect(0, 0, w, h)
    { }

    virtual uint32_t size() const = 0;

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

    virtual void clear(color_t col) = 0;

    virtual BufferType * getPixelPointer(int x, int y) const = 0;

    virtual color_t getPixel(int x, int y) const = 0;
    virtual void setPixel(int x, int y, color_t col, PixelOp op = PixelOp::DEFAULT) = 0;

    void fillRect(int x, int y, int w, int h, color_t col, PixelOp op = PixelOp::DEFAULT) {
        fillRect(Rect(x, y, w, h), col, op);
    }

    virtual void fillRect(Rect rect, color_t col, PixelOp op = PixelOp::DEFAULT) = 0;

    void drawRect(int x, int y, int w, int h, color_t col, Pen pen = DEFAULT_PEN) {
        int r = x + w;
        int b = y + h;
        drawLine(x, y, r, y, col, pen);
        drawLine(r, y, r, b, col, pen);
        drawLine(r, b, x, b, col, pen);
        drawLine(x, b, x, y, col, pen);
    }

    void drawLine(int x0, int y0, int x1, int y1, color_t col, Pen pen = DEFAULT_PEN) {
        x0 *= fxp12::ONE;
        y0 *= fxp12::ONE;
        x1 *= fxp12::ONE;
        y1 *= fxp12::ONE;
        drawLineF(x0, y0, x1, y1, col, pen);
    }

    void drawLineF(int32_t x0f, int32_t y0f, int32_t x1f, int32_t y1f, color_t col, Pen pen = DEFAULT_PEN) {
        int32_t dxf = x1f - x0f;
        int32_t dyf = y1f - y0f;
        bool dotted = pen.dotPeriod > 0;
        uint32_t sreg = pen.dotPattern;
        if (nyna::abs(dxf) > nyna::abs(dyf)) {
            int xi = fxp12::floorToInt(x0f);
            int n = nyna::abs(fxp12::floorToInt(x1f) - xi);
            int xi_step = dxf >= 0 ? 1 : -1;
            for (int i = 0; i < n; i++) {
                int yi = fxp12::floorToInt(y0f + dyf * i / n);
                if (dotted) {
                    if (sreg & 1) setPixel(xi, yi, col, pen.op);
                    sreg = (sreg >> 1) | ((sreg & 1) << (pen.dotPeriod - 1));
                }
                else {
                    setPixel(xi, yi, col, pen.op);
                }
                xi += xi_step;
            }
        }
        else {
            int yi = fxp12::floorToInt(y0f);
            int n = nyna::abs(fxp12::floorToInt(y1f) - yi);
            int yi_step = dyf >= 0 ? 1 : -1;
            for (int i = 0; i < n; i++) {
                int xi = fxp12::floorToInt(x0f + dxf * i / n);
                if (dotted) {
                    if (sreg & 1) setPixel(xi, yi, col, pen.op);
                    sreg = (sreg >> 1) | ((sreg & 1) << (pen.dotPeriod - 1));
                }
                else {
                    setPixel(xi, yi, col, pen.op);
                }
                yi += yi_step;
            }
        }
    }

    void fillEllipseF(int x, int y, int w, int h, color_t col, PixelOp op = PixelOp::DEFAULT) {
        fillEllipseF(Rect(x, y, w, h), col, op);
    }

    void fillEllipseF(const Rect rectf, color_t col, PixelOp op = PixelOp::DEFAULT) {
        Rect dest_rect = rectf;
        const int r = (dest_rect.right() + fxp12::ONE - 1) / fxp12::ONE;
        const int b = (dest_rect.bottom() + fxp12::ONE - 1) / fxp12::ONE;
        dest_rect.x /= fxp12::ONE;
        dest_rect.y /= fxp12::ONE;
        dest_rect.width = r - dest_rect.x;
        dest_rect.height = b - dest_rect.y;
        dest_rect.intersectSelf(clipRect);
        if (dest_rect.width <= 0 || dest_rect.height <= 0) return;
        const int rxf = rectf.width / 2;
        const int ryf = rectf.height / 2;
        const int cxf = rectf.x + rxf;
        const int cyf = rectf.y + ryf;
        const int dx0 = dest_rect.x;
        const int dy0 = dest_rect.y;
        const int dx1 = dest_rect.right();
        const int dy1 = dest_rect.bottom();
        
        // 楕円内かどうかをピクセル中心で判定するため 0.5px オフセットする
        int yf = dy0 * fxp12::ONE + (fxp12::ONE / 2);
        for (int y = dy0; y < dy1; y++) {
            int rdy = (yf - cyf) * fxp12::ONE / ryf;
            int rdy2 = rdy * rdy;
            int xf = dx0 * fxp12::ONE + (fxp12::ONE / 2);
            for (int x = dx0; x < dx1; x++) {
                int rdx = (xf - cxf) * fxp12::ONE / rxf;
                int rdx2 = rdx * rdx;
                if (rdx2 + rdy2 < fxp12::ONE * fxp12::ONE) {
                    setPixel(x, y, col, op);
                }
                xf += fxp12::ONE;
            }
            yf += fxp12::ONE;
        }
    }

    int drawString(const TinyFont &font, int dx0, int dy0, const char* str, color_t col, PixelOp op = PixelOp::DEFAULT) {
        const char *ptr = str;
        char c;
        while ((c = *(ptr++)) != '\0') {
            dx0 += drawChar(font, dx0, dy0, c, col, op) + font.spacing;
        }
        return dx0;
    }

    virtual int drawChar(const TinyFont &font, int dx0, int dy0, char code, color_t col, PixelOp op = PixelOp::DEFAULT) = 0;

    void drawBitmap(int dx0, int dy0, const Bitmap &src, PixelOp op = PixelOp::DEFAULT) {
        drawBitmap(dx0, dy0, src, src.getBounds(), op);
    }

    virtual void drawBitmap(int dx0, int dy0, const Bitmap &src, Rect srcRect, PixelOp op = PixelOp::DEFAULT) {
        int dr = dx0 + srcRect.width;
        int db = dy0 + srcRect.height;
        int sy = srcRect.y;
        for (int dy = dy0; dy < db; dy++, sy++) {
            int sx = srcRect.x;
            for (int dx = dx0; dx < dr; dx++, sx++) {
                setPixel(dx, dy, src.getPixel(sx, sy), op);
            }
        }
    }
};

}
