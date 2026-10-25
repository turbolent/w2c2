
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.2.h"

void test() {
    m6_elemX2E2Instance instance;
    m6_elemX2E2Instantiate(&instance, resolveTestImports);
    printStart("elem.2.wasm");
}
