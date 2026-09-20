
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.10.h"

void test() {
    m7_elemX2E10Instance instance;
    m7_elemX2E10Instantiate(&instance, resolveTestImports);
    printStart("elem.10.wasm");
}
