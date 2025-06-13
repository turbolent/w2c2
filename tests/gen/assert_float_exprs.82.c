
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.82.h"

void test() {
    floatexprs82Instance instance;
    floatexprs82Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.82.wasm");
    assertEqualF32(
        floatexprs82_f32X2Ecompute_radix(&instance, 1.0, 1.0),
        2.0,
        "f32.compute_radix(1.0, 1.0)"
    );
    assertEqualF64(
        floatexprs82_f64X2Ecompute_radix(&instance, 1.0, 1.0),
        2.0,
        "f64.compute_radix(1.0, 1.0)"
    );
}
