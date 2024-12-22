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

enum class PixelOperation {
    COPY = 0,
    OR = 1,
    AND = 2,
    XOR = 3,
    NOP = 7,
};

union PixelMethod {
    uint8_t raw;
    struct {
        PixelOperation op : 3;
        bool srcNot : 1;
    };
    PixelMethod(uint8_t raw) : raw(raw) {}
};



//enum class PixelMethod : uint8_t {
//    NOP = 0,
//    OP_COPY = 1,
//    OP_OR = 2,
//    OP_AND = 3,
//    OP_XOR = 4,
//    OP_MASK = (0x7),
//    SRC_NOT = (1 << 3),
//};
//PixelMethod operator | (PixelMethod a, PixelMethod b) {
//    return static_cast<PixelMethod>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
//}
//PixelMethod operator & (PixelMethod a, PixelMethod b) {
//    return static_cast<PixelMethod>(static_cast<uint8_t>(a) & static_cast<uint8_t>(b));
//}
//explicit operator bool(PixelMethod a) const {
//    
//}

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

Rect clip_rect(const Rect rect, int w, int h);

}
