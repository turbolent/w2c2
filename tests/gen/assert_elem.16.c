
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.16.h"

void test() {
    m7_elemX2E16Instance instance;
    m7_elemX2E16Instantiate(&instance, resolveTestImports);
    printStart("elem.16.wasm");
}
