
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.5.h"

void test() {
    m13_memoryX5FfillX2E5Instance instance;
    m13_memoryX5FfillX2E5Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.5.wasm");
}
