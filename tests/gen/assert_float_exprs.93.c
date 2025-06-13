
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.93.h"

void test() {
    floatexprs93Instance instance;
    floatexprs93Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.93.wasm");
    assertEqualF32(
        floatexprs93_f32X2Egolden_ratio(&instance, 0.5, 1.0, 5.0),
        1.6180340051651,
        "f32.golden_ratio(0.5, 1.0, 5.0)"
    );
    assertEqualF64(
        floatexprs93_f64X2Egolden_ratio(&instance, 0.5, 1.0, 5.0),
        1.618033988749895,
        "f64.golden_ratio(0.5, 1.0, 5.0)"
    );
}
