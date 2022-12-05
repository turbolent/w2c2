
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.10.h"

void test() {
    floatexprs10Instance instance;
    floatexprs10Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.10.wasm");
}
