
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.20.h"

void test() {
    memoryinit20Instance instance;
    memoryinit20Instantiate(&instance, resolveTestImports);
    printStart("memory_init.20.wasm");
}
