
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.7.h"

void test() {
    memoryinit7Instance instance;
    memoryinit7Instantiate(&instance, resolveTestImports);
    printStart("memory_init.7.wasm");
}
