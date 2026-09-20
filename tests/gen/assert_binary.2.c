
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.2.h"

void test() {
    m8_binaryX2E2Instance instance;
    m8_binaryX2E2Instantiate(&instance, resolveTestImports);
    printStart("binary.2.wasm");
}
