
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.0.h"

void test() {
    m8_memoryX2E0Instance instance;
    m8_memoryX2E0Instantiate(&instance, resolveTestImports);
    printStart("memory.0.wasm");
}
