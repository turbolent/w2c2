
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.46.h"

void test() {
    m14_floatX5FexprsX2E46Instance instance;
    m14_floatX5FexprsX2E46Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.46.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FltX5Fif(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_lt_if(0.0, -0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FltX5Fif(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_lt_if(-0.0, 0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FleX5Fif(&instance, 0.0, -0.0),
        0.0,
        "f32.no_fold_le_if(0.0, -0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FleX5Fif(&instance, -0.0, 0.0),
        -0.0,
        "f32.no_fold_le_if(-0.0, 0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgtX5Fif(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_gt_if(0.0, -0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgtX5Fif(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_gt_if(-0.0, 0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgeX5Fif(&instance, 0.0, -0.0),
        0.0,
        "f32.no_fold_ge_if(0.0, -0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E46Export17_f32X2EnoX5FfoldX5FgeX5Fif(&instance, -0.0, 0.0),
        -0.0,
        "f32.no_fold_ge_if(-0.0, 0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FltX5Fif(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_lt_if(0.0, -0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FltX5Fif(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_lt_if(-0.0, 0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FleX5Fif(&instance, 0.0, -0.0),
        0.0,
        "f64.no_fold_le_if(0.0, -0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FleX5Fif(&instance, -0.0, 0.0),
        -0.0,
        "f64.no_fold_le_if(-0.0, 0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgtX5Fif(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_gt_if(0.0, -0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgtX5Fif(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_gt_if(-0.0, 0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgeX5Fif(&instance, 0.0, -0.0),
        0.0,
        "f64.no_fold_ge_if(0.0, -0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E46Export17_f64X2EnoX5FfoldX5FgeX5Fif(&instance, -0.0, 0.0),
        -0.0,
        "f64.no_fold_ge_if(-0.0, 0.0)"
    );
}
