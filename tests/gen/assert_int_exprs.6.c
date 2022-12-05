
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.6.h"

void test() {
    intexprs6Instance instance;
    intexprs6Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.6.wasm");
}
