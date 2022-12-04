
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.48.h"

void test() {
    floatexprs48Instance instance;
    floatexprs48Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.48.wasm");
    assertEqualF32(
        floatexprs48_calculate(&instance),
        -466.9268493652344,
        "calculate()"
    );
}
