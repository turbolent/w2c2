
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.19.h"

void test() {
    memoryinit19Instance instance;
    memoryinit19Instantiate(&instance, resolveTestImports);
    printStart("memory_init.19.wasm");
    memoryinit19_test(&instance);
    printOK("test()");
}
