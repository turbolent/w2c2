
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.11.h"

void test() {
    m7_elemX2E11Instance instance;
    m7_elemX2E11Instantiate(&instance, resolveTestImports);
    printStart("elem.11.wasm");
}
