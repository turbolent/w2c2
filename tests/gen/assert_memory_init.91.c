#include "test.h"
#include "test_memory_init.91.h"

void test(void) {
    static m14_memoryX5FinitX2E91Instance instance;
    m14_memoryX5FinitX2E91Instantiate(&instance, resolveTestImports);
    printStart("memory_init.91.wasm");
    (void)(m14_memoryX5FinitX2E91Export4_test(&instance));
    printOK("test()");
    m14_memoryX5FinitX2E91FreeInstance(&instance);
}
