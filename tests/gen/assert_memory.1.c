
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.1.h"

void test() {
    memory1Instance instance;
    memory1Instantiate(&instance, resolveTestImports);
    printStart("memory.1.wasm");
}
