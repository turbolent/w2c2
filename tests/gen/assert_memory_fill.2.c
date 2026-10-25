
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.2.h"

void test() {
    m13_memoryX5FfillX2E2Instance instance;
    m13_memoryX5FfillX2E2Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.2.wasm");
}
