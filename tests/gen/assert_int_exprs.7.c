
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.7.h"

void test() {
    intexprs7Instance instance;
    intexprs7Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.7.wasm");
}
