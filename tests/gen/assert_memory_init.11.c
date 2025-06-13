
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.11.h"

void test() {
    memoryinit11Instance instance;
    memoryinit11Instantiate(&instance, resolveTestImports);
    printStart("memory_init.11.wasm");
    memoryinit11_test(&instance);
    printOK("test()");
}
