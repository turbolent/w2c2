
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.9.h"

void test() {
    m6_elemX2E9Instance instance;
    m6_elemX2E9Instantiate(&instance, resolveTestImports);
    printStart("elem.9.wasm");
}
