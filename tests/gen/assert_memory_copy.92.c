
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.92.h"

void test() {
    m14_memoryX5FcopyX2E92Instance instance;
    m14_memoryX5FcopyX2E92Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.92.wasm");
    m14_memoryX5FcopyX2E92Export4_test(&instance);
    printOK("test()");
}
