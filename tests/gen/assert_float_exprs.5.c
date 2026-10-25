
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.5.h"

void test() {
    m13_floatX5FexprsX2E5Instance instance;
    m13_floatX5FexprsX2E5Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.5.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m13_floatX5FexprsX2E5Export20_f32X2EnoX5FfoldX5FmulX5Fzero(&instance, -0.0)),
        2147483648u,
        "f32.no_fold_mul_zero(-0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_floatX5FexprsX2E5Export20_f32X2EnoX5FfoldX5FmulX5Fzero(&instance, -1.0)),
        2147483648u,
        "f32.no_fold_mul_zero(-1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m13_floatX5FexprsX2E5Export20_f32X2EnoX5FfoldX5FmulX5Fzero(&instance, -2.0)),
        2147483648u,
        "f32.no_fold_mul_zero(-2.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m13_floatX5FexprsX2E5Export20_f32X2EnoX5FfoldX5FmulX5Fzero(&instance, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "f32.no_fold_mul_zero(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_floatX5FexprsX2E5Export20_f64X2EnoX5FfoldX5FmulX5Fzero(&instance, -0.0)),
        9223372036854775808ull,
        "f64.no_fold_mul_zero(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_floatX5FexprsX2E5Export20_f64X2EnoX5FfoldX5FmulX5Fzero(&instance, -1.0)),
        9223372036854775808ull,
        "f64.no_fold_mul_zero(-1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m13_floatX5FexprsX2E5Export20_f64X2EnoX5FfoldX5FmulX5Fzero(&instance, -2.0)),
        9223372036854775808ull,
        "f64.no_fold_mul_zero(-2.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m13_floatX5FexprsX2E5Export20_f64X2EnoX5FfoldX5FmulX5Fzero(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "f64.no_fold_mul_zero(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
}
