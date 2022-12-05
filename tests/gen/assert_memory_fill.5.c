
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_fill.5.h"

void test() {
    memoryfill5Instance instance;
    memoryfill5Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.5.wasm");
}
