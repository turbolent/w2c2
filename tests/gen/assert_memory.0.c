
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.0.h"

void test() {
    memory0Instance instance;
    memory0Instantiate(&instance, resolveTestImports);
    printStart("memory.0.wasm");
}
