
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.0.h"

void test() {
    m8_binaryX2E0Instance instance;
    m8_binaryX2E0Instantiate(&instance, resolveTestImports);
    printStart("binary.0.wasm");
}
