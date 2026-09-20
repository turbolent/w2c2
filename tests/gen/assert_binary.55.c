
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.55.h"

void test() {
    m9_binaryX2E55Instance instance;
    m9_binaryX2E55Instantiate(&instance, resolveTestImports);
    printStart("binary.55.wasm");
}
