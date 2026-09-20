
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.0.h"

void test() {
    m6_elemX2E0Instance instance;
    m6_elemX2E0Instantiate(&instance, resolveTestImports);
    printStart("elem.0.wasm");
}
