
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.1.h"

void test() {
    m13_memoryX5FfillX2E1Instance instance;
    m13_memoryX5FfillX2E1Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.1.wasm");
}
