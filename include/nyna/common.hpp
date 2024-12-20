#pragma once

#include <stdint.h>

#define NYNA_INLINE inline __attribute__((always_inline))
#define NYNA_STATIC_INLINE static NYNA_INLINE

// todo 全部 inline 関数にする
#define NYNA_MIN(a, b) ((a) < (b) ? (a) : (b))
#define NYNA_MAX(a, b) ((a) > (b) ? (a) : (b))
#define NYNA_CLIP(min, max, val) (NYNA_MAX((min), NYNA_MIN((max), (val))))

// todo 全部 inline 関数にする
#define NYNA_CEIL_DIV(a, b) (((a) + (b) - 1) / (b))
#define NYNA_ROUND_DIV(a, b) (((a) + ((b) / 2)) / (b))

// todo 全部 inline 関数にする
#define NYNA_CYCLIC_INCR(x, period) (((x) + 1 < (period)) ? ((x) + 1) : 0)
#define NYNA_CYCLIC_DECR(x, period) (((x) - 1 >= 0) ? ((x) - 1) : (period) - 1)

namespace nyna {

template<typename T>
NYNA_STATIC_INLINE T abs(T x) { return x >= 0 ? x : -x; };

template<typename T>
NYNA_STATIC_INLINE int sign(T x) { return x < 0 ? -1 : (x == 0 ? 0 : 1); };

NYNA_STATIC_INLINE int32_t cyclicNorm(int32_t x, int32_t period) {
    if (x < 0) {
        do { x += period; } while (x < 0);
    }
    else if (x >= period) {
        do { x -= period; } while (x >= period);
    }
    return x;
}

NYNA_STATIC_INLINE int32_t cyclicAdd(int32_t a, int32_t b, int32_t period) {
    return cyclicNorm(a + b, period);
}

NYNA_STATIC_INLINE int32_t cyclicDiff(int32_t a, int32_t b, int32_t period) {
    return cyclicNorm(a - b + (period / 2), period) - (period / 2);
}

NYNA_STATIC_INLINE int32_t cyclicFollow(int32_t x, int32_t goal, int32_t period, int32_t ratioFxp, int fxpPrec, int32_t maxSpeed = -1) {
    int32_t diff = cyclicDiff(goal, x, period);
    if (diff == 0) return x;
    int32_t step = NYNA_ROUND_DIV(diff * ratioFxp, 1 << fxpPrec);
    if (step == 0) {
        step = diff >= 0 ? 1 : -1;
    }
    else if (maxSpeed > 0) {
        step = NYNA_CLIP(-maxSpeed, maxSpeed, step);
    }
    return cyclicAdd(x, step, period);
}

}
