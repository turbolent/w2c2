
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.54.h"

void test() {
    floatexprs54Instance instance;
    floatexprs54Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.54.wasm");
    assertEqualF32(
        floatexprs54_inverse(&instance, 96.0),
        0.010416666977107525,
        "inverse(96.0)"
    );
}
