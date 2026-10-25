
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.23.h"

void test() {
    m14_floatX5FexprsX2E23Instance instance;
    m14_floatX5FexprsX2E23Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.23.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, 1.0)),
        2139095040u,
        "f32.no_fold_div_0(1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, -1.0)),
        4286578688u,
        "f32.no_fold_div_0(-1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, INFINITY)),
        2139095040u,
        "f32.no_fold_div_0(INFINITY)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, -INFINITY)),
        4286578688u,
        "f32.no_fold_div_0(-INFINITY)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, 0.0)) & 2147483647u),
        2143289344u,
        "f32.no_fold_div_0(0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, -0.0)) & 2147483647u),
        2143289344u,
        "f32.no_fold_div_0(-0.0)"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, f32_reinterpret_i32(0x7fa00000u))) & 2143289344u),
        2143289344u,
        "f32.no_fold_div_0(f32_reinterpret_i32(0x7fa00000u))"
    );
    assertEqualU32(
        (i32_reinterpret_f32(m14_floatX5FexprsX2E23Export17_f32X2EnoX5FfoldX5FdivX5F0(&instance, f32_reinterpret_i32(0x7fc00000u))) & 2147483647u),
        2143289344u,
        "f32.no_fold_div_0(f32_reinterpret_i32(0x7fc00000u))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, 1.0)),
        9218868437227405312ull,
        "f64.no_fold_div_0(1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, -1.0)),
        18442240474082181120ull,
        "f64.no_fold_div_0(-1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, INFINITY)),
        9218868437227405312ull,
        "f64.no_fold_div_0(INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, -INFINITY)),
        18442240474082181120ull,
        "f64.no_fold_div_0(-INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_div_0(0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_div_0(-0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "f64.no_fold_div_0(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m14_floatX5FexprsX2E23Export17_f64X2EnoX5FfoldX5FdivX5F0(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "f64.no_fold_div_0(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
}
