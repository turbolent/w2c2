
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.90.h"

void test() {
    memorycopy90Instance instance;
    memorycopy90Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.90.wasm");
    memorycopy90_test(&instance);
    printOK("test()");
}
