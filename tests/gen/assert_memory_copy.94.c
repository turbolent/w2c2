
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.94.h"

void test() {
    m14_memoryX5FcopyX2E94Instance instance;
    m14_memoryX5FcopyX2E94Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.94.wasm");
    m14_memoryX5FcopyX2E94Export4_test(&instance);
    printOK("test()");
}
