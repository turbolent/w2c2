
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.88.h"

void test() {
    m14_floatX5FexprsX2E88Instance instance;
    m14_floatX5FexprsX2E88Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.88.wasm");
    assertEqualU32(
        m14_floatX5FexprsX2E88Export20_f32X2EnoX5FtrichotomyX5Flt(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u)),
        0u,
        "f32.no_trichotomy_lt(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E88Export20_f32X2EnoX5FtrichotomyX5Fle(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u)),
        0u,
        "f32.no_trichotomy_le(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E88Export20_f32X2EnoX5FtrichotomyX5Fgt(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u)),
        0u,
        "f32.no_trichotomy_gt(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E88Export20_f32X2EnoX5FtrichotomyX5Fge(&instance, 0.0, f32_reinterpret_i32(0x7fc00000u)),
        0u,
        "f32.no_trichotomy_ge(0.0, f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E88Export20_f64X2EnoX5FtrichotomyX5Flt(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull)),
        0u,
        "f64.no_trichotomy_lt(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E88Export20_f64X2EnoX5FtrichotomyX5Fle(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull)),
        0u,
        "f64.no_trichotomy_le(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E88Export20_f64X2EnoX5FtrichotomyX5Fgt(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull)),
        0u,
        "f64.no_trichotomy_gt(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E88Export20_f64X2EnoX5FtrichotomyX5Fge(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull)),
        0u,
        "f64.no_trichotomy_ge(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
}
