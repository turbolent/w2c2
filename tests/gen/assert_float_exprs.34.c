
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.34.h"

void test() {
    floatexprs34Instance instance;
    floatexprs34Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.34.wasm");
    assertEqualF32(
        floatexprs34_f32X2EnoX5FfoldX5Fdiv2X5Fmul2(&instance, 2.3509885615147286e-38),
        2.350988701644575e-38,
        "f32.no_fold_div2_mul2(2.3509885615147286e-38)"
    );
    assertEqualF64(
        floatexprs34_f64X2EnoX5FfoldX5Fdiv2X5Fmul2(&instance, 4.4501477170144023e-308),
        4.450147717014403e-308,
        "f64.no_fold_div2_mul2(4.4501477170144023e-308)"
    );
}
