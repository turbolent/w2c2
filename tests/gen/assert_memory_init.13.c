
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.13.h"

void test() {
    memoryinit13Instance instance;
    memoryinit13Instantiate(&instance, resolveTestImports);
    printStart("memory_init.13.wasm");
}
