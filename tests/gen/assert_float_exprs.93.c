
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.93.h"

void test() {
    floatexprs93Instance instance;
    floatexprs93Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.93.wasm");
    assertEqualU32(
        floatexprs93_pointX5Ffour(&instance, 4.0, 10.0),
        0u,
        "point_four(4.0, 10.0)"
    );
}
