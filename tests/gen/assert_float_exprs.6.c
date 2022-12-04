
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.6.h"

void test() {
    floatexprs6Instance instance;
    floatexprs6Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.6.wasm");
}
