
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.87.h"

void test() {
    memorycopy87Instance instance;
    memorycopy87Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.87.wasm");
}
