
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.109.h"

void test() {
    m10_binaryX2E109Instance instance;
    m10_binaryX2E109Instantiate(&instance, resolveTestImports);
    printStart("binary.109.wasm");
}
