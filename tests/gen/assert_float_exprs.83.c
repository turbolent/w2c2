
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.83.h"

void test() {
    floatexprs83Instance instance;
    floatexprs83Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.83.wasm");
}
