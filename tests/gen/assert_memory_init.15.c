
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.15.h"

void test() {
    memoryinit15Instance instance;
    memoryinit15Instantiate(&instance, resolveTestImports);
    printStart("memory_init.15.wasm");
}
