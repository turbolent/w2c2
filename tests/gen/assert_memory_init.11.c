
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.11.h"

void test() {
    m14_memoryX5FinitX2E11Instance instance;
    m14_memoryX5FinitX2E11Instantiate(&instance, resolveTestImports);
    printStart("memory_init.11.wasm");
    m14_memoryX5FinitX2E11Export4_test(&instance);
    printOK("test()");
}
