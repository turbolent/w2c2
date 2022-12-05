
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.18.h"

void test() {
    intexprs18Instance instance;
    intexprs18Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.18.wasm");
}
