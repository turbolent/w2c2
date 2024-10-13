
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.56.h"

void test() {
    floatexprs56Instance instance;
    floatexprs56Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.56.wasm");
    assertEqualF32(
        floatexprs56_inverse(&instance, 96.0),
        0.010416666977107525,
        "inverse(96.0)"
    );
}
