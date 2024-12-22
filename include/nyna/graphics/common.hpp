#pragma once

#include <stdint.h>

#include "nyna/math_utils.hpp"

#define NYNA_CFG_BYTES_PER_PIXEL (1)

namespace nyna::graphics {

#if NYNA_CFG_BYTES_PER_PIXEL == 1
using color_t = uint8_t;
static constexpr color_t BLACK = 0;
static constexpr color_t WHITE = 1;
#else
#error "Unsupported pixel format."
#endif

class Rect {
public:
    int x, y, width, height;
    
    Rect() : x(0), y(0), width(0), height(0) {}
    Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) { }
    
    int right() const { return x + width; }
    int bottom() const { return y + height; }
    int centerX() const { return (x + width / 2); }
    int centerY() const { return (y + height / 2); }

    int contains(int dx, int dy) const {
        return
            x <= dx && dx < (x + width) && 
            y <= dy && dy < (y + height);
    }

    void offsetSelf(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void intersectSelf(Rect other) {
        int r = NYNA_MIN(x + width, other.x + other.width);
        int b = NYNA_MIN(y + height, other.y + other.height);
        x = NYNA_MAX(x, other.x);
        y = NYNA_MAX(y, other.y);
        width = r - x;
        height = b - y;
    }
    
    void inflateSelf(int xSize, int ySize) {
        x -= xSize;
        y -= ySize;
        width += xSize * 2;
        height += ySize * 2;
    }
};

enum class PixelOp : uint8_t {
    EMPTY = 0,
    GATE_COPY = 0,
    GATE_OR = 1,
    GATE_AND = 2,
    GATE_XOR = 3,
    GATE_MASK = 0xf,
    SRC_NOT = (1 << 4),
    SRC_PATTERN = (1 << 5),
    DEFAULT = GATE_COPY,
};

constexpr PixelOp operator | (PixelOp a, PixelOp b) {
    return static_cast<PixelOp>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

constexpr PixelOp operator & (PixelOp a, PixelOp b) {
    return static_cast<PixelOp>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
}

constexpr PixelOp operator |= (PixelOp &l, PixelOp r) { return l = (l | r); }
constexpr PixelOp operator &= (PixelOp &l, PixelOp r) { return l = (l & r); }

struct Pen {
    PixelOp op;
    uint8_t dotPeriod;
    uint32_t dotPattern;
    Pen(
        PixelOp op = PixelOp::DEFAULT,
        uint8_t dotPeriod = 0,
        uint32_t dotPattern = 0x55555555ul
    ) : 
        op(op),
        dotPeriod(dotPeriod),
        dotPattern(dotPattern)
    { }
};
static const Pen DEFAULT_PEN;

}
