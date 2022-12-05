
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.93.h"

void test() {
    memorycopy93Instance instance;
    memorycopy93Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.93.wasm");
}
