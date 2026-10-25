
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_start.5.h"

void test() {
    m7_startX2E5Instance instance;
    m7_startX2E5Instantiate(&instance, resolveTestImports);
    printStart("start.5.wasm");
}
