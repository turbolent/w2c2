
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_init.18.h"

void test() {
    memoryinit18Instance instance;
    memoryinit18Instantiate(&instance, resolveTestImports);
    printStart("memory_init.18.wasm");
    memoryinit18_test(&instance);
    printOK("test()");
}
