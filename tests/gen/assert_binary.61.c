
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.61.h"

void test() {
    m9_binaryX2E61Instance instance;
    m9_binaryX2E61Instantiate(&instance, resolveTestImports);
    printStart("binary.61.wasm");
}
