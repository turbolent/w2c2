
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.85.h"

void test() {
    memorycopy85Instance instance;
    memorycopy85Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.85.wasm");
}
