
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.15.h"

void test() {
    floatexprs15Instance instance;
    floatexprs15Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.15.wasm");
}
