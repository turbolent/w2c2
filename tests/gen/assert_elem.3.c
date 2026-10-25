
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.3.h"

void test() {
    m6_elemX2E3Instance instance;
    m6_elemX2E3Instantiate(&instance, resolveTestImports);
    printStart("elem.3.wasm");
}
