
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_start.7.h"

void test() {
    m7_startX2E7Instance instance;
    m7_startX2E7Instantiate(&instance, resolveTestImports);
    printStart("start.7.wasm");
}
