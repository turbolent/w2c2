
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.95.h"

void test() {
    floatexprs95Instance instance;
    floatexprs95Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.95.wasm");
    assertEqualF32(
        floatexprs95_f32X2Eno_fold_conditional_inc(&instance, -0.0, -1.0),
        -0.0,
        "f32.no_fold_conditional_inc(-0.0, -1.0)"
    );
    assertEqualF64(
        floatexprs95_f64X2Eno_fold_conditional_inc(&instance, -0.0, -1.0),
        -0.0,
        "f64.no_fold_conditional_inc(-0.0, -1.0)"
    );
}
