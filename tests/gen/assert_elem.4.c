
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.4.h"

void test() {
    m6_elemX2E4Instance instance;
    m6_elemX2E4Instantiate(&instance, resolveTestImports);
    printStart("elem.4.wasm");
}
