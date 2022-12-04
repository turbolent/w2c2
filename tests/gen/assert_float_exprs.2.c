
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.2.h"

void test() {
    floatexprs2Instance instance;
    floatexprs2Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.2.wasm");
    assertEqualF32(
        floatexprs2_f32X2EnoX5FfoldX5FaddX5Fzero(&instance, -0.0),
        0.0,
        "f32.no_fold_add_zero(-0.0)"
    );
    assertEqualF64(
        floatexprs2_f64X2EnoX5FfoldX5FaddX5Fzero(&instance, -0.0),
        0.0,
        "f64.no_fold_add_zero(-0.0)"
    );
}
