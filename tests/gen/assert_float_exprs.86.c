
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.86.h"

void test() {
    floatexprs86Instance instance;
    floatexprs86Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.86.wasm");
}
