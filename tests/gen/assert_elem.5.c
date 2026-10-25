
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.5.h"

void test() {
    m6_elemX2E5Instance instance;
    m6_elemX2E5Instantiate(&instance, resolveTestImports);
    printStart("elem.5.wasm");
}
