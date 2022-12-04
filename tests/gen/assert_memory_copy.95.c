
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.95.h"

void test() {
    memorycopy95Instance instance;
    memorycopy95Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.95.wasm");
}
