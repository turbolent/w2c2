
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.4.h"

void test() {
    memoryfill4Instance instance;
    memoryfill4Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.4.wasm");
    memoryfill4_test(&instance);
    printOK("test()");
}
