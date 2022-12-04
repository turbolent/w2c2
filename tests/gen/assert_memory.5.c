
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.5.h"

void test() {
    memory5Instance instance;
    memory5Instantiate(&instance, resolveTestImports);
    printStart("memory.5.wasm");
}
