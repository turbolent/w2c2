
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.23.h"

void test() {
    floatexprs23Instance instance;
    floatexprs23Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.23.wasm");
    assertEqualF32(
        floatexprs23_f32X2Eno_fold_div_0(&instance, 1.0),
        INFINITY,
        "f32.no_fold_div_0(1.0)"
    );
    assertEqualF32(
        floatexprs23_f32X2Eno_fold_div_0(&instance, -1.0),
        -INFINITY,
        "f32.no_fold_div_0(-1.0)"
    );
    assertEqualF32(
        floatexprs23_f32X2Eno_fold_div_0(&instance, INFINITY),
        INFINITY,
        "f32.no_fold_div_0(INFINITY)"
    );
    assertEqualF32(
        floatexprs23_f32X2Eno_fold_div_0(&instance, -INFINITY),
        -INFINITY,
        "f32.no_fold_div_0(-INFINITY)"
    );
    assertEqualF64(
        floatexprs23_f64X2Eno_fold_div_0(&instance, 1.0),
        INFINITY,
        "f64.no_fold_div_0(1.0)"
    );
    assertEqualF64(
        floatexprs23_f64X2Eno_fold_div_0(&instance, -1.0),
        -INFINITY,
        "f64.no_fold_div_0(-1.0)"
    );
    assertEqualF64(
        floatexprs23_f64X2Eno_fold_div_0(&instance, INFINITY),
        INFINITY,
        "f64.no_fold_div_0(INFINITY)"
    );
    assertEqualF64(
        floatexprs23_f64X2Eno_fold_div_0(&instance, -INFINITY),
        -INFINITY,
        "f64.no_fold_div_0(-INFINITY)"
    );
}
