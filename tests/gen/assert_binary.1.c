
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.1.h"

void test() {
    m8_binaryX2E1Instance instance;
    m8_binaryX2E1Instantiate(&instance, resolveTestImports);
    printStart("binary.1.wasm");
}
