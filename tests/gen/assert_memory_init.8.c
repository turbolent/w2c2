
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.8.h"

void test() {
    memoryinit8Instance instance;
    memoryinit8Instantiate(&instance, resolveTestImports);
    printStart("memory_init.8.wasm");
}
