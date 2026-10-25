
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.7.h"

void test() {
    m13_floatX5FexprsX2E7Instance instance;
    m13_floatX5FexprsX2E7Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.7.wasm");
    assertEqualU32(
        (i32_reinterpret_f32(m13_floatX5FexprsX2E7Export20_f32X2EnoX5FfoldX5FzeroX5Fdiv(&instance, 0.0)) & 2147483647u),
        2143289344u,
        "f32.no_fold_zero_div(0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m13_floatX5FexprsX2E7Export20_f32X2EnoX5FfoldX5FzeroX5Fdiv(&instance, -0.0)) & 2147483647u),
        2143289344u,
        "f32.no_fold_zero_div(-0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m13_floatX5FexprsX2E7Export20_f32X2EnoX5FfoldX5FzeroX5Fdiv(&instance, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "f32.no_fold_zero_div(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m13_floatX5FexprsX2E7Export20_f32X2EnoX5FfoldX5FzeroX5Fdiv(&instance, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "f32.no_fold_zero_div(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m13_floatX5FexprsX2E7Export20_f64X2EnoX5FfoldX5FzeroX5Fdiv(&instance, 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_zero_div(0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m13_floatX5FexprsX2E7Export20_f64X2EnoX5FfoldX5FzeroX5Fdiv(&instance, -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_zero_div(-0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m13_floatX5FexprsX2E7Export20_f64X2EnoX5FfoldX5FzeroX5Fdiv(&instance, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_zero_div(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m13_floatX5FexprsX2E7Export20_f64X2EnoX5FfoldX5FzeroX5Fdiv(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "f64.no_fold_zero_div(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
}
