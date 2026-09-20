
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.81.h"

void test() {
    m9_binaryX2E81Instance instance;
    m9_binaryX2E81Instantiate(&instance, resolveTestImports);
    printStart("binary.81.wasm");
}
