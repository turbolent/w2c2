#include "test.h"
#include "test_memory_copy.87.h"

void test(void) {
    static m14_memoryX5FcopyX2E87Instance instance;
    m14_memoryX5FcopyX2E87Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.87.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FcopyX2E87Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FcopyX2E87FreeInstance(&instance);
}
