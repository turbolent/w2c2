
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.98.h"

void test() {
    m9_binaryX2E98Instance instance;
    m9_binaryX2E98Instantiate(&instance, resolveTestImports);
    printStart("binary.98.wasm");
}
