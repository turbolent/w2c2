
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.1.h"

void test() {
    m8_memoryX2E1Instance instance;
    m8_memoryX2E1Instantiate(&instance, resolveTestImports);
    printStart("memory.1.wasm");
}
