
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.90.h"

void test() {
    memoryinit90Instance instance;
    memoryinit90Instantiate(&instance, resolveTestImports);
    printStart("memory_init.90.wasm");
}
