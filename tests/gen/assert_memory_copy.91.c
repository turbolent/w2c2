#include "test.h"
#include "test_memory_copy.91.h"

void test(void) {
    static m14_memoryX5FcopyX2E91Instance instance;
    m14_memoryX5FcopyX2E91Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.91.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FcopyX2E91Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FcopyX2E91FreeInstance(&instance);
}
