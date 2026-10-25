
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.17.h"

void test() {
    m14_memoryX5FinitX2E17Instance instance;
    m14_memoryX5FinitX2E17Instantiate(&instance, resolveTestImports);
    printStart("memory_init.17.wasm");
}
