
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.18.h"

void test() {
    m7_elemX2E18Instance instance;
    m7_elemX2E18Instantiate(&instance, resolveTestImports);
    printStart("elem.18.wasm");
}
