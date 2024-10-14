
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.51.h"

void test() {
    floatexprs51Instance instance;
    floatexprs51Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.51.wasm");
    assertEqualF64(
        floatexprs51_calculate(&instance),
        -466.926956301738,
        "calculate()"
    );
}
