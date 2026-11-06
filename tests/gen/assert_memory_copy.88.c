#include "test.h"
#include "test_memory_copy.88.h"

void test(void) {
    static m14_memoryX5FcopyX2E88Instance instance;
    m14_memoryX5FcopyX2E88Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.88.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FcopyX2E88Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FcopyX2E88FreeInstance(&instance);
}
