
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.16.h"

void test() {
    floatexprs16Instance instance;
    floatexprs16Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.16.wasm");
    assertEqualF32(
        floatexprs16_f32X2EnoX5FfoldX5FdivX5F3(&instance, -1361678981660672.0),
        -453892982702080.0,
        "f32.no_fold_div_3(-1361678981660672.0)"
    );
    assertEqualF32(
        floatexprs16_f32X2EnoX5FfoldX5FdivX5F3(&instance, -1.873688036745896e+28),
        -6.245626592387716e+27,
        "f32.no_fold_div_3(-1.873688036745896e+28)"
    );
    assertEqualF32(
        floatexprs16_f32X2EnoX5FfoldX5FdivX5F3(&instance, -1.2045130720366438e-25),
        -4.0150434707392155e-26,
        "f32.no_fold_div_3(-1.2045130720366438e-25)"
    );
    assertEqualF32(
        floatexprs16_f32X2EnoX5FfoldX5FdivX5F3(&instance, -5.281345934922403e-38),
        -1.7604485982641855e-38,
        "f32.no_fold_div_3(-5.281345934922403e-38)"
    );
    assertEqualF32(
        floatexprs16_f32X2EnoX5FfoldX5FdivX5F3(&instance, -2.5495562672178882e-17),
        -8.498520614999423e-18,
        "f32.no_fold_div_3(-2.5495562672178882e-17)"
    );
    assertEqualF64(
        floatexprs16_f64X2EnoX5FfoldX5FdivX5F3(&instance, -2.9563579573969634e+190),
        -9.854526524656545e+189,
        "f64.no_fold_div_3(-2.9563579573969634e+190)"
    );
    assertEqualF64(
        floatexprs16_f64X2EnoX5FfoldX5FdivX5F3(&instance, -9.291150921449772e-51),
        -3.097050307149924e-51,
        "f64.no_fold_div_3(-9.291150921449772e-51)"
    );
    assertEqualF64(
        floatexprs16_f64X2EnoX5FfoldX5FdivX5F3(&instance, 1.3808061543557006e-263),
        4.602687181185669e-264,
        "f64.no_fold_div_3(1.3808061543557006e-263)"
    );
    assertEqualF64(
        floatexprs16_f64X2EnoX5FfoldX5FdivX5F3(&instance, -1.378076163468349e+303),
        -4.593587211561163e+302,
        "f64.no_fold_div_3(-1.378076163468349e+303)"
    );
    assertEqualF64(
        floatexprs16_f64X2EnoX5FfoldX5FdivX5F3(&instance, 8.632400808831366e+124),
        2.877466936277122e+124,
        "f64.no_fold_div_3(8.632400808831366e+124)"
    );
}
