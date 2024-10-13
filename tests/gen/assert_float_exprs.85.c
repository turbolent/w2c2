
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.85.h"

void test() {
    floatexprs85Instance instance;
    floatexprs85Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.85.wasm");
}
