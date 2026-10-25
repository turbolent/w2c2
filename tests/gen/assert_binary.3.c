
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.3.h"

void test() {
    m8_binaryX2E3Instance instance;
    m8_binaryX2E3Instantiate(&instance, resolveTestImports);
    printStart("binary.3.wasm");
}
