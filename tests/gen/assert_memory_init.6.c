
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.6.h"

void test() {
    m13_memoryX5FinitX2E6Instance instance;
    m13_memoryX5FinitX2E6Instantiate(&instance, resolveTestImports);
    printStart("memory_init.6.wasm");
    m13_memoryX5FinitX2E6Export4_test(&instance);
    printOK("test()");
}
