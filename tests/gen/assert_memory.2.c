
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.2.h"

void test() {
    m8_memoryX2E2Instance instance;
    m8_memoryX2E2Instantiate(&instance, resolveTestImports);
    printStart("memory.2.wasm");
}
