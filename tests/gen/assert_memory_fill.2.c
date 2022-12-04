
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.2.h"

void test() {
    memoryfill2Instance instance;
    memoryfill2Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.2.wasm");
}
