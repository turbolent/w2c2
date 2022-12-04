
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.1.h"

void test() {
    memoryfill1Instance instance;
    memoryfill1Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.1.wasm");
}
