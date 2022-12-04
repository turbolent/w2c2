
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.94.h"

void test() {
    memorycopy94Instance instance;
    memorycopy94Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.94.wasm");
    memorycopy94_test(&instance);
    printOK("test()");
}
