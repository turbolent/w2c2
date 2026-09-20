
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.5.h"

void test() {
    m8_memoryX2E5Instance instance;
    m8_memoryX2E5Instantiate(&instance, resolveTestImports);
    printStart("memory.5.wasm");
}
