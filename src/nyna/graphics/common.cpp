#include "nyna/math_utils.hpp"
#include "nyna/graphics/common.hpp"

namespace nyna::graphics {

Rect clip_rect(Rect rect, int w, int h) {
    int r = rect.r(), b = rect.b();
    rect.x = NYNA_CLIP(0, w, rect.x);
    rect.y = NYNA_CLIP(0, h, rect.y);
    rect.w = NYNA_CLIP(0, w, r) - rect.x;
    rect.h = NYNA_CLIP(0, h, b) - rect.y;
    return rect;
}

}
