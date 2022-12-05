
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.2.h"

void test() {
    memory2Instance instance;
    memory2Instantiate(&instance, resolveTestImports);
    printStart("memory.2.wasm");
}
