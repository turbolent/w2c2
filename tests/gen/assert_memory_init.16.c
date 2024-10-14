
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.16.h"

void test() {
    memoryinit16Instance instance;
    memoryinit16Instantiate(&instance, resolveTestImports);
    printStart("memory_init.16.wasm");
    memoryinit16_test(&instance);
    printOK("test()");
}
