
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.64.h"

void test() {
    floatexprs64Instance instance;
    floatexprs64Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.64.wasm");
    assertEqualF32(
        floatexprs64_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, -0.0),
        0.0,
        "f32.no_fold_neg_add(-0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs64_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, -0.0),
        -0.0,
        "f32.no_fold_neg_add(0.0, -0.0)"
    );
    assertEqualF32(
        floatexprs64_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, 0.0),
        -0.0,
        "f32.no_fold_neg_add(-0.0, 0.0)"
    );
    assertEqualF32(
        floatexprs64_f32X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, 0.0),
        -0.0,
        "f32.no_fold_neg_add(0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs64_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, -0.0),
        0.0,
        "f64.no_fold_neg_add(-0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs64_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, -0.0),
        -0.0,
        "f64.no_fold_neg_add(0.0, -0.0)"
    );
    assertEqualF64(
        floatexprs64_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, -0.0, 0.0),
        -0.0,
        "f64.no_fold_neg_add(-0.0, 0.0)"
    );
    assertEqualF64(
        floatexprs64_f64X2EnoX5FfoldX5FnegX5Fadd(&instance, 0.0, 0.0),
        -0.0,
        "f64.no_fold_neg_add(0.0, 0.0)"
    );
}
