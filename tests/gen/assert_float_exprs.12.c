
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.12.h"

void test() {
    floatexprs12Instance instance;
    floatexprs12Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.12.wasm");
}
