
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.6.h"

void test() {
    memoryinit6Instance instance;
    memoryinit6Instantiate(&instance, resolveTestImports);
    printStart("memory_init.6.wasm");
    memoryinit6_test(&instance);
    printOK("test()");
}
