
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.83.h"

void test() {
    floatexprs83Instance instance;
    floatexprs83Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.83.wasm");
    assertEqualF32(
        floatexprs83_f32X2Eno_fold_sub1_mul_add(&instance, 2.3283064365386963e-10, 1.0),
        0.0,
        "f32.no_fold_sub1_mul_add(2.3283064365386963e-10, 1.0)"
    );
    assertEqualF64(
        floatexprs83_f64X2Eno_fold_sub1_mul_add(&instance, 5.421010862427522e-20, 1.0),
        0.0,
        "f64.no_fold_sub1_mul_add(5.421010862427522e-20, 1.0)"
    );
}
