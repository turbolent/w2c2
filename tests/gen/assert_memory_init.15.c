
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.15.h"

void test() {
    m14_memoryX5FinitX2E15Instance instance;
    m14_memoryX5FinitX2E15Instantiate(&instance, resolveTestImports);
    printStart("memory_init.15.wasm");
}
