
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.6.h"

void test() {
    m6_elemX2E6Instance instance;
    m6_elemX2E6Instantiate(&instance, resolveTestImports);
    printStart("elem.6.wasm");
}
