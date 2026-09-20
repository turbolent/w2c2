
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.85.h"

void test() {
    m14_floatX5FexprsX2E85Instance instance;
    m14_floatX5FexprsX2E85Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.85.wasm");
    assertEqualU32(
        m14_floatX5FexprsX2E85Export10_f32X2EnotX5Flt(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0),
        1u,
        "f32.not_lt(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E85Export10_f32X2EnotX5Fle(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0),
        1u,
        "f32.not_le(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E85Export10_f32X2EnotX5Fgt(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0),
        1u,
        "f32.not_gt(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E85Export10_f32X2EnotX5Fge(&instance, f32_reinterpret_i32(0x7fc00000u), 0.0),
        1u,
        "f32.not_ge(f32_reinterpret_i32(0x7fc00000u), 0.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E85Export10_f64X2EnotX5Flt(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0),
        1u,
        "f64.not_lt(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E85Export10_f64X2EnotX5Fle(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0),
        1u,
        "f64.not_le(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E85Export10_f64X2EnotX5Fgt(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0),
        1u,
        "f64.not_gt(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU32(
        m14_floatX5FexprsX2E85Export10_f64X2EnotX5Fge(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0),
        1u,
        "f64.not_ge(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
}
