
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.48.h"

void test() {
    m14_floatX5FexprsX2E48Instance instance;
    m14_floatX5FexprsX2E48Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.48.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E48Export24_f32X2EnoX5FfoldX5FltX5FifX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f32.no_fold_lt_if_to_abs(0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E48Export24_f32X2EnoX5FfoldX5FltX5FifX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f32.no_fold_lt_if_to_abs(-0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E48Export24_f32X2EnoX5FfoldX5FleX5FifX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f32.no_fold_le_if_to_abs(0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E48Export24_f32X2EnoX5FfoldX5FleX5FifX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f32.no_fold_le_if_to_abs(-0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E48Export24_f32X2EnoX5FfoldX5FgtX5FifX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f32.no_fold_gt_if_to_abs(0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E48Export24_f32X2EnoX5FfoldX5FgtX5FifX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f32.no_fold_gt_if_to_abs(-0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E48Export24_f32X2EnoX5FfoldX5FgeX5FifX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f32.no_fold_ge_if_to_abs(0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E48Export24_f32X2EnoX5FfoldX5FgeX5FifX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f32.no_fold_ge_if_to_abs(-0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E48Export24_f64X2EnoX5FfoldX5FltX5FifX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f64.no_fold_lt_if_to_abs(0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E48Export24_f64X2EnoX5FfoldX5FltX5FifX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f64.no_fold_lt_if_to_abs(-0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E48Export24_f64X2EnoX5FfoldX5FleX5FifX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f64.no_fold_le_if_to_abs(0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E48Export24_f64X2EnoX5FfoldX5FleX5FifX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f64.no_fold_le_if_to_abs(-0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E48Export24_f64X2EnoX5FfoldX5FgtX5FifX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f64.no_fold_gt_if_to_abs(0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E48Export24_f64X2EnoX5FfoldX5FgtX5FifX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f64.no_fold_gt_if_to_abs(-0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E48Export24_f64X2EnoX5FfoldX5FgeX5FifX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f64.no_fold_ge_if_to_abs(0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E48Export24_f64X2EnoX5FfoldX5FgeX5FifX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f64.no_fold_ge_if_to_abs(-0.0)"
    );
}
