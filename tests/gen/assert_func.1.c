
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func.1.h"

void test() {
    m6_funcX2E1Instance instance;
    m6_funcX2E1Instantiate(&instance, resolveTestImports);
    printStart("func.1.wasm");
}
