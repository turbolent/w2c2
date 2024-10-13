
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.95.h"

void test() {
    floatexprs95Instance instance;
    floatexprs95Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.95.wasm");
    assertEqualU32(
        floatexprs95_point_four(&instance, 4.0, 10.0),
        0u,
        "point_four(4.0, 10.0)"
    );
}
