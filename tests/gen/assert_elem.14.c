
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.14.h"

void test() {
    m7_elemX2E14Instance instance;
    m7_elemX2E14Instantiate(&instance, resolveTestImports);
    printStart("elem.14.wasm");
}
