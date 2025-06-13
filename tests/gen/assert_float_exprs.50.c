
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.50.h"

void test() {
    floatexprs50Instance instance;
    floatexprs50Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.50.wasm");
    assertEqualF32(
        floatexprs50_calculate(&instance),
        -466.9268493652344,
        "calculate()"
    );
}
