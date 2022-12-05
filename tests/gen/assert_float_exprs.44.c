
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.44.h"

void test() {
    floatexprs44Instance instance;
    floatexprs44Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.44.wasm");
    assertEqualF32(
        floatexprs44_f32X2EnoX5FfoldX5FltX5Fif(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_lt_if(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs44_f32X2EnoX5FfoldX5FltX5Fif(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_lt_if(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs44_f32X2EnoX5FfoldX5FleX5Fif(&instance, 0.0, -0.0),
        0.0,
        "f32.no_fold_le_if(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs44_f32X2EnoX5FfoldX5FleX5Fif(&instance, -0.0, 0.0),
        -0.0,
        "f32.no_fold_le_if(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs44_f32X2EnoX5FfoldX5FgtX5Fif(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_gt_if(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs44_f32X2EnoX5FfoldX5FgtX5Fif(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_gt_if(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs44_f32X2EnoX5FfoldX5FgeX5Fif(&instance, 0.0, -0.0),
        0.0,
        "f32.no_fold_ge_if(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs44_f32X2EnoX5FfoldX5FgeX5Fif(&instance, -0.0, 0.0),
        -0.0,
        "f32.no_fold_ge_if(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs44_f64X2EnoX5FfoldX5FltX5Fif(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_lt_if(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs44_f64X2EnoX5FfoldX5FltX5Fif(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_lt_if(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs44_f64X2EnoX5FfoldX5FleX5Fif(&instance, 0.0, -0.0),
        0.0,
        "f64.no_fold_le_if(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs44_f64X2EnoX5FfoldX5FleX5Fif(&instance, -0.0, 0.0),
        -0.0,
        "f64.no_fold_le_if(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs44_f64X2EnoX5FfoldX5FgtX5Fif(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_gt_if(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs44_f64X2EnoX5FfoldX5FgtX5Fif(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_gt_if(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs44_f64X2EnoX5FfoldX5FgeX5Fif(&instance, 0.0, -0.0),
        0.0,
        "f64.no_fold_ge_if(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs44_f64X2EnoX5FfoldX5FgeX5Fif(&instance, -0.0, 0.0),
        -0.0,
        "f64.no_fold_ge_if(-0.0, 0.0)"
    );
}
