
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.88.h"

void test() {
    memorycopy88Instance instance;
    memorycopy88Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.88.wasm");
}
