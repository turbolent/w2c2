
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.92.h"

void test() {
    m9_binaryX2E92Instance instance;
    m9_binaryX2E92Instantiate(&instance, resolveTestImports);
    printStart("binary.92.wasm");
}
