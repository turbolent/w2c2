
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.3.h"

void test() {
    memory3Instance instance;
    memory3Instantiate(&instance, resolveTestImports);
    printStart("memory.3.wasm");
}
