
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.3.h"

void test() {
    floatexprs3Instance instance;
    floatexprs3Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.3.wasm");
    assertEqualF32(
        floatexprs3_f32X2Eno_fold_zero_sub(&instance, 0.0),
        0.0,
        "f32.no_fold_zero_sub(0.0)"
    );
    assertEqualF64(
        floatexprs3_f64X2Eno_fold_zero_sub(&instance, 0.0),
        0.0,
        "f64.no_fold_zero_sub(0.0)"
    );
}
