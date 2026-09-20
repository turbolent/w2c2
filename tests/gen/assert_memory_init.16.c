
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.16.h"

void test() {
    m14_memoryX5FinitX2E16Instance instance;
    m14_memoryX5FinitX2E16Instantiate(&instance, resolveTestImports);
    printStart("memory_init.16.wasm");
    m14_memoryX5FinitX2E16Export4_test(&instance);
    printOK("test()");
}
