
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.19.h"

void test() {
    m14_memoryX5FinitX2E19Instance instance;
    m14_memoryX5FinitX2E19Instantiate(&instance, resolveTestImports);
    printStart("memory_init.19.wasm");
    m14_memoryX5FinitX2E19Export4_test(&instance);
    printOK("test()");
}
