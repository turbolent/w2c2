#include "test.h"
#include "test_memory_copy.93.h"

void test(void) {
    static m14_memoryX5FcopyX2E93Instance instance;
    m14_memoryX5FcopyX2E93Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.93.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FcopyX2E93Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FcopyX2E93FreeInstance(&instance);
}
