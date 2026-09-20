
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.66.h"

void test() {
    m14_floatX5FexprsX2E66Instance instance;
    m14_floatX5FexprsX2E66Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.66.wasm");
    assertEqualF32(
        m14_floatX5FexprsX2E66Export19_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, -0.0),
        0.0,
        "f32.no_fold_neg_add(-0.0, -0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E66Export19_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_neg_add(0.0, -0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E66Export19_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, 0.0),
        -0.0,
        "f32.no_fold_neg_add(-0.0, 0.0)"
    );
    assertEqualF32(
        m14_floatX5FexprsX2E66Export19_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, 0.0),
        -0.0,
        "f32.no_fold_neg_add(0.0, 0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E66Export19_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, -0.0),
        0.0,
        "f64.no_fold_neg_add(-0.0, -0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E66Export19_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_neg_add(0.0, -0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E66Export19_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, 0.0),
        -0.0,
        "f64.no_fold_neg_add(-0.0, 0.0)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E66Export19_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, 0.0),
        -0.0,
        "f64.no_fold_neg_add(0.0, 0.0)"
    );
}
