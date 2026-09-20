
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.65.h"

void test() {
    m14_floatX5FexprsX2E65Instance instance;
    m14_floatX5FexprsX2E65Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.65.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E65Export19_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, -0.0),
        -0.0,
        "f32.no_fold_neg_sub(-0.0, -0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E65Export19_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_neg_sub(0.0, -0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E65Export19_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, 0.0),
        0.0,
        "f32.no_fold_neg_sub(-0.0, 0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E65Export19_f32X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, 0.0),
        -0.0,
        "f32.no_fold_neg_sub(0.0, 0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E65Export19_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, -0.0),
        -0.0,
        "f64.no_fold_neg_sub(-0.0, -0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E65Export19_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_neg_sub(0.0, -0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E65Export19_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, -0.0, 0.0),
        0.0,
        "f64.no_fold_neg_sub(-0.0, 0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E65Export19_f64X2EnoX5FfoldX5FnegX5Fsub(&instance, 0.0, 0.0),
        -0.0,
        "f64.no_fold_neg_sub(0.0, 0.0)"
    );
}
