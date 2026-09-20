
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.18.h"

void test() {
    m14_memoryX5FinitX2E18Instance instance;
    m14_memoryX5FinitX2E18Instantiate(&instance, resolveTestImports);
    printStart("memory_init.18.wasm");
    m14_memoryX5FinitX2E18Export4_test(&instance);
    printOK("test()");
}
