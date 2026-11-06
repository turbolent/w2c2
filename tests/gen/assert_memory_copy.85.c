#include "test.h"
#include "test_memory_copy.85.h"

void test(void) {
    static m14_memoryX5FcopyX2E85Instance instance;
    m14_memoryX5FcopyX2E85Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.85.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FcopyX2E85Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FcopyX2E85FreeInstance(&instance);
}
