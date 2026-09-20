
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.15.h"

void test() {
    m14_floatX5FexprsX2E15Instance instance;
    m14_floatX5FexprsX2E15Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.15.wasm");
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E15Export20_f32X2EnoX5FfoldX5FdivX5Fself(&instance, INFINITY)) & 2147483647u),
        2143289344u,
        "f32.no_fold_div_self(INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E15Export20_f32X2EnoX5FfoldX5FdivX5Fself(&instance, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "f32.no_fold_div_self(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E15Export20_f32X2EnoX5FfoldX5FdivX5Fself(&instance, 0.0)) & 2147483647u),
        2143289344u,
        "f32.no_fold_div_self(0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E15Export20_f32X2EnoX5FfoldX5FdivX5Fself(&instance, -0.0)) & 2147483647u),
        2143289344u,
        "f32.no_fold_div_self(-0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E15Export20_f64X2EnoX5FfoldX5FdivX5Fself(&instance, INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_div_self(INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E15Export20_f64X2EnoX5FfoldX5FdivX5Fself(&instance, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_div_self(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E15Export20_f64X2EnoX5FfoldX5FdivX5Fself(&instance, 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_div_self(0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E15Export20_f64X2EnoX5FfoldX5FdivX5Fself(&instance, -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_div_self(-0.0)"
    );
}
