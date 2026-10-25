
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.16.h"

void test() {
    m14_floatX5FexprsX2E16Instance instance;
    m14_floatX5FexprsX2E16Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.16.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E16Export17_f32X2EnoX5FfoldX5FdivX5F3(&instance, -1361678981660672.0)),
        3620628505u,
        "f32.no_fold_div_3(-1361678981660672.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E16Export17_f32X2EnoX5FfoldX5FdivX5F3(&instance, -1.873688036745896e+28)),
        3986780695u,
        "f32.no_fold_div_3(-1.873688036745896e+28)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E16Export17_f32X2EnoX5FfoldX5FdivX5F3(&instance, -1.2045130720366438e-25)),
        2504446137u,
        "f32.no_fold_div_3(-1.2045130720366438e-25)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E16Export17_f32X2EnoX5FfoldX5FdivX5F3(&instance, -5.281345934922403e-38)),
        2160046629u,
        "f32.no_fold_div_3(-5.281345934922403e-38)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E16Export17_f32X2EnoX5FfoldX5FdivX5F3(&instance, -2.5495562672178882e-17)),
        2736571681u,
        "f32.no_fold_div_3(-2.5495562672178882e-17)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E16Export17_f64X2EnoX5FfoldX5FdivX5F3(&instance, -2.9563579573969634e+190)),
        16672802667330368301ull,
        "f64.no_fold_div_3(-2.9563579573969634e+190)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E16Export17_f64X2EnoX5FfoldX5FdivX5F3(&instance, -9.291150921449772e-51)),
        13074664638073319671ull,
        "f64.no_fold_div_3(-9.291150921449772e-51)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E16Export17_f64X2EnoX5FfoldX5FdivX5F3(&instance, 1.3808061543557006e-263)),
        667250911628840899ull,
        "f64.no_fold_div_3(1.3808061543557006e-263)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E16Export17_f64X2EnoX5FfoldX5FdivX5F3(&instance, -1.378076163468349e+303)),
        18358201936817915643ull,
        "f64.no_fold_div_3(-1.378076163468349e+303)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E16Export17_f64X2EnoX5FfoldX5FdivX5F3(&instance, 8.632400808831366e+124)),
        6468791534604471399ull,
        "f64.no_fold_div_3(8.632400808831366e+124)"
    );
}
