
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.80.h"

void test() {
    floatexprs80Instance instance;
    floatexprs80Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.80.wasm");
    assertEqualF32(
        floatexprs80_f32X2EcomputeX5Fradix(&instance, 1.0, 1.0),
        2.0,
        "f32.compute_radix(1.0, 1.0)"
    );
    assertEqualF64(
        floatexprs80_f64X2EcomputeX5Fradix(&instance, 1.0, 1.0),
        2.0,
        "f64.compute_radix(1.0, 1.0)"
    );
}
