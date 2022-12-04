
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.86.h"

void test() {
    memorycopy86Instance instance;
    memorycopy86Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.86.wasm");
}
