
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.4.h"

void test() {
    m13_memoryX5FfillX2E4Instance instance;
    m13_memoryX5FfillX2E4Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.4.wasm");
    m13_memoryX5FfillX2E4Export4_test(&instance);
    printOK("test()");
}
