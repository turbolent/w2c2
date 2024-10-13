
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.14.h"

void test() {
    memoryinit14Instance instance;
    memoryinit14Instantiate(&instance, resolveTestImports);
    printStart("memory_init.14.wasm");
}
