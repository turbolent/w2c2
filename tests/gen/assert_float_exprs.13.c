
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.13.h"

void test() {
    floatexprs13Instance instance;
    floatexprs13Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.13.wasm");
}
