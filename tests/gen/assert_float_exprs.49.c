
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.49.h"

void test() {
    floatexprs49Instance instance;
    floatexprs49Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.49.wasm");
    assertEqualF64(
        floatexprs49_calculate(&instance),
        -466.926956301738,
        "calculate()"
    );
}
