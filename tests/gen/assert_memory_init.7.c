
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.7.h"

void test() {
    m13_memoryX5FinitX2E7Instance instance;
    m13_memoryX5FinitX2E7Instantiate(&instance, resolveTestImports);
    printStart("memory_init.7.wasm");
}
