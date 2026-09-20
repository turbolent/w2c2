
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.67.h"

void test() {
    m14_floatX5FexprsX2E67Instance instance;
    m14_floatX5FexprsX2E67Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.67.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E67Export23_f32X2EnoX5FfoldX5FaddX5FnegX5Fneg(&instance, -0.0, -0.0),
        0.0,
        "f32.no_fold_add_neg_neg(-0.0, -0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E67Export23_f32X2EnoX5FfoldX5FaddX5FnegX5Fneg(&instance, 0.0, -0.0),
        0.0,
        "f32.no_fold_add_neg_neg(0.0, -0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E67Export23_f32X2EnoX5FfoldX5FaddX5FnegX5Fneg(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_add_neg_neg(-0.0, 0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E67Export23_f32X2EnoX5FfoldX5FaddX5FnegX5Fneg(&instance, 0.0, 0.0),
        -0.0,
        "f32.no_fold_add_neg_neg(0.0, 0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E67Export23_f64X2EnoX5FfoldX5FaddX5FnegX5Fneg(&instance, -0.0, -0.0),
        0.0,
        "f64.no_fold_add_neg_neg(-0.0, -0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E67Export23_f64X2EnoX5FfoldX5FaddX5FnegX5Fneg(&instance, 0.0, -0.0),
        0.0,
        "f64.no_fold_add_neg_neg(0.0, -0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E67Export23_f64X2EnoX5FfoldX5FaddX5FnegX5Fneg(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_add_neg_neg(-0.0, 0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E67Export23_f64X2EnoX5FfoldX5FaddX5FnegX5Fneg(&instance, 0.0, 0.0),
        -0.0,
        "f64.no_fold_add_neg_neg(0.0, 0.0)"
    );
}
