
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.4.h"

void test() {
    m8_memoryX2E4Instance instance;
    m8_memoryX2E4Instantiate(&instance, resolveTestImports);
    printStart("memory.4.wasm");
}
