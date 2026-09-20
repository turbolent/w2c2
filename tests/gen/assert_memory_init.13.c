
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.13.h"

void test() {
    m14_memoryX5FinitX2E13Instance instance;
    m14_memoryX5FinitX2E13Instantiate(&instance, resolveTestImports);
    printStart("memory_init.13.wasm");
}
