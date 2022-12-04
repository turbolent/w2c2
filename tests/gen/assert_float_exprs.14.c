
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.14.h"

void test() {
    floatexprs14Instance instance;
    floatexprs14Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.14.wasm");
}
