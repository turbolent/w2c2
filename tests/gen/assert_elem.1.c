
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.1.h"

void test() {
    m6_elemX2E1Instance instance;
    m6_elemX2E1Instantiate(&instance, resolveTestImports);
    printStart("elem.1.wasm");
}
