
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.8.h"

void test() {
    m13_memoryX5FinitX2E8Instance instance;
    m13_memoryX5FinitX2E8Instantiate(&instance, resolveTestImports);
    printStart("memory_init.8.wasm");
}
