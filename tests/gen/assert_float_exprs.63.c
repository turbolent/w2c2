
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.63.h"

void test() {
    floatexprs63Instance instance;
    floatexprs63Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.63.wasm");
    assertEqualF32(
        floatexprs63_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, -0.0),
        -0.0,
        "f32.no_fold_neg_sub(-0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs63_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_neg_sub(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs63_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_neg_sub(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs63_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, 0.0),
        -0.0,
        "f32.no_fold_neg_sub(0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs63_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, -0.0),
        -0.0,
        "f64.no_fold_neg_sub(-0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs63_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_neg_sub(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs63_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_neg_sub(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs63_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, 0.0),
        -0.0,
        "f64.no_fold_neg_sub(0.0, 0.0)"
    );
}
