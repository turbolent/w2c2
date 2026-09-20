#include <stdio.h>
#include <stdlib.h>
#include "runtime_plan9_test.h"

/* Exercise the APE math fallbacks on the native test host. */
#ifndef PLAN9
#define PLAN9 1
#endif
#ifdef __GNUC__
#define inline __inline__
#endif
#include "w2c2_base.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL testRuntimePlan9: line %d\n", __LINE__); \
            exit(1); \
        } \
    } while (0)

void
testRuntimePlan9(void) {
    static const struct {
        F64 value;
        F64 truncated;
        F64 nearest;
    } cases[] = {
        {0.0, 0.0, 0.0},
        {0.25, 0.0, 0.0},
        {0.5, 0.0, 0.0},
        {0.75, 0.0, 1.0},
        {1.5, 1.0, 2.0},
        {2.5, 2.0, 2.0},
        {3.5, 3.0, 4.0},
        {4503599627370495.5, 4503599627370495.0, 4503599627370496.0},
        {4503599627370496.0, 4503599627370496.0, 4503599627370496.0}
    };
    static const U64 preserved[] = {
        W2C2_LL(0x0000000000000000U),
        W2C2_LL(0x8000000000000000U),
        W2C2_LL(0x7ff0000000000000U),
        W2C2_LL(0xfff0000000000000U),
        W2C2_LL(0x7ff8000000000042U),
        W2C2_LL(0xfff8000000000042U)
    };
    size_t i;
    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++) {
        U32 negative;
        for (negative = 0; negative < 2; negative++) {
            const F64 sign = negative ? -1.0 : 1.0;
            const F64 value = copysign(cases[i].value, sign);
            CHECK(i64_reinterpret_f64(trunc(value))
                == i64_reinterpret_f64(copysign(cases[i].truncated, sign)));
            CHECK(i64_reinterpret_f64(nearbyint(value))
                == i64_reinterpret_f64(copysign(cases[i].nearest, sign)));
            if (i < 7) {
                CHECK(i32_reinterpret_f32(truncf((F32)value))
                    == i32_reinterpret_f32(copysignf((F32)cases[i].truncated, (F32)sign)));
                CHECK(i32_reinterpret_f32(nearbyintf((F32)value))
                    == i32_reinterpret_f32(copysignf((F32)cases[i].nearest, (F32)sign)));
            }
        }
    }
    for (i = 0; i < sizeof(preserved) / sizeof(preserved[0]); i++) {
        const F64 value = f64_reinterpret_i64(preserved[i]);
        CHECK(i64_reinterpret_f64(trunc(value)) == preserved[i]);
        CHECK(i64_reinterpret_f64(nearbyint(value)) == preserved[i]);
    }
    CHECK(i64_reinterpret_f64(nearbyint(f64_reinterpret_i64(1))) == 0);
    CHECK(i64_reinterpret_f64(nearbyint(f64_reinterpret_i64(W2C2_LL(0x3fe0000000000001U))))
        == W2C2_LL(0x3ff0000000000000U));
    CHECK(i32_reinterpret_f32(copysignf(f32_reinterpret_i32(0x7fc00042U), -1.0F))
        == 0xffc00042U);
    CHECK(i64_reinterpret_f64(copysign(f64_reinterpret_i64(W2C2_LL(0x7ff8000000000042U)), -1.0))
        == W2C2_LL(0xfff8000000000042U));
    CHECK(signbit(-0.0) && !signbit(0.0));
    CHECK(i32_reinterpret_f32(fabsf(-0.0F)) == 0);
    CHECK(sqrtf(4.0F) == 2.0F);
    CHECK(ceilf(-1.5F) == -1.0F && floorf(-1.5F) == -2.0F);
    fprintf(stderr, "PASS testRuntimePlan9\n");
}
