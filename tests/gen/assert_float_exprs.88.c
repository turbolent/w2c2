
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.88.h"

void test() {
    floatexprs88Instance instance;
    floatexprs88Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.88.wasm");
}
