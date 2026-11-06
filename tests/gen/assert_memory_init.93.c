#include "test.h"
#include "test_memory_init.93.h"

void test(void) {
    static m14_memoryX5FinitX2E93Instance instance;
    m14_memoryX5FinitX2E93Instantiate(&instance, resolveTestImports);
    printStart("memory_init.93.wasm");
    (void)(m14_memoryX5FinitX2E93Export4_test(&instance));
    printOK("test()");
    m14_memoryX5FinitX2E93FreeInstance(&instance);
}
