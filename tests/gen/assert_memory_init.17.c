
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.17.h"

void test() {
    memoryinit17Instance instance;
    memoryinit17Instantiate(&instance, resolveTestImports);
    printStart("memory_init.17.wasm");
}
