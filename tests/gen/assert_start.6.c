
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_start.6.h"

void test() {
    m7_startX2E6Instance instance;
    m7_startX2E6Instantiate(&instance, resolveTestImports);
    printStart("start.6.wasm");
}
