
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.4.h"

void test() {
    memory4Instance instance;
    memory4Instantiate(&instance, resolveTestImports);
    printStart("memory.4.wasm");
}
