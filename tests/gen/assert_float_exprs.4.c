
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.4.h"

void test() {
    floatexprs4Instance instance;
    floatexprs4Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.4.wasm");
}
