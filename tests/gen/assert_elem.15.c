
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.15.h"

void test() {
    m7_elemX2E15Instance instance;
    m7_elemX2E15Instantiate(&instance, resolveTestImports);
    printStart("elem.15.wasm");
}
