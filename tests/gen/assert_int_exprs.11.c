
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.11.h"

void test() {
    intexprs11Instance instance;
    intexprs11Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.11.wasm");
}
