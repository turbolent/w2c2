
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.12.h"

void test() {
    memoryinit12Instance instance;
    memoryinit12Instantiate(&instance, resolveTestImports);
    printStart("memory_init.12.wasm");
}
