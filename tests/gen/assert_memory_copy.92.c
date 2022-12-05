
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.92.h"

void test() {
    memorycopy92Instance instance;
    memorycopy92Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.92.wasm");
    memorycopy92_test(&instance);
    printOK("test()");
}
