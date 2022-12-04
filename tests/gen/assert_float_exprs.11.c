
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.11.h"

void test() {
    floatexprs11Instance instance;
    floatexprs11Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.11.wasm");
}
