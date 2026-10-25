
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.13.h"

void test() {
    m7_elemX2E13Instance instance;
    m7_elemX2E13Instantiate(&instance, resolveTestImports);
    printStart("elem.13.wasm");
}
