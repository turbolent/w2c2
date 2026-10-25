
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.17.h"

void test() {
    m7_elemX2E17Instance instance;
    m7_elemX2E17Instantiate(&instance, resolveTestImports);
    printStart("elem.17.wasm");
}
