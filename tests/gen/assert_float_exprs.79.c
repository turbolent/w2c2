
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.79.h"

void test() {
    floatexprs79Instance instance;
    floatexprs79Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.79.wasm");
    assertEqualU32(
        floatexprs79_f32X2Eno_extended_precision_div(&instance, 3.0, 7.0, 0.4285714328289032),
        1u,
        "f32.no_extended_precision_div(3.0, 7.0, 0.4285714328289032)"
    );
    assertEqualU32(
        floatexprs79_f64X2Eno_extended_precision_div(&instance, 3.0, 7.0, 0.42857142857142855),
        1u,
        "f64.no_extended_precision_div(3.0, 7.0, 0.42857142857142855)"
    );
}
