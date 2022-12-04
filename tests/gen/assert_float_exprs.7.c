
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.7.h"

void test() {
    floatexprs7Instance instance;
    floatexprs7Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.7.wasm");
}
