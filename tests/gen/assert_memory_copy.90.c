
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.90.h"

void test() {
    m14_memoryX5FcopyX2E90Instance instance;
    m14_memoryX5FcopyX2E90Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.90.wasm");
    m14_memoryX5FcopyX2E90Export4_test(&instance);
    printOK("test()");
}
