
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.47.h"

void test() {
    m14_floatX5FexprsX2E47Instance instance;
    m14_floatX5FexprsX2E47Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.47.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f32.no_fold_lt_select_to_abs(0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f32.no_fold_lt_select_to_abs(-0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f32.no_fold_le_select_to_abs(0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f32.no_fold_le_select_to_abs(-0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f32.no_fold_gt_select_to_abs(0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f32.no_fold_gt_select_to_abs(-0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f32.no_fold_ge_select_to_abs(0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E47Export28_f32X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f32.no_fold_ge_select_to_abs(-0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f64.no_fold_lt_select_to_abs(0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FltX5FselectX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f64.no_fold_lt_select_to_abs(-0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f64.no_fold_le_select_to_abs(0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FleX5FselectX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f64.no_fold_le_select_to_abs(-0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, 0.0),
        -0.0,
        "f64.no_fold_gt_select_to_abs(0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgtX5FselectX5FtoX5Fabs(&instance, -0.0),
        0.0,
        "f64.no_fold_gt_select_to_abs(-0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, 0.0),
        0.0,
        "f64.no_fold_ge_select_to_abs(0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E47Export28_f64X2EnoX5FfoldX5FgeX5FselectX5FtoX5Fabs(&instance, -0.0),
        -0.0,
        "f64.no_fold_ge_select_to_abs(-0.0)"
    );
}
