
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.68.h"

void test() {
    floatexprs68Instance instance;
    floatexprs68Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.68.wasm");
    assertEqualF32(
        floatexprs68_f32X2Eno_fold_add_neg(&instance, 0.0),
        0.0,
        "f32.no_fold_add_neg(0.0)"
    );
    assertEqualF32(
        floatexprs68_f32X2Eno_fold_add_neg(&instance, -0.0),
        0.0,
        "f32.no_fold_add_neg(-0.0)"
    );
    assertEqualF64(
        floatexprs68_f64X2Eno_fold_add_neg(&instance, 0.0),
        0.0,
        "f64.no_fold_add_neg(0.0)"
    );
    assertEqualF64(
        floatexprs68_f64X2Eno_fold_add_neg(&instance, -0.0),
        0.0,
        "f64.no_fold_add_neg(-0.0)"
    );
}
