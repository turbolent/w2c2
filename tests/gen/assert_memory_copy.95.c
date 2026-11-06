#include "test.h"
#include "test_memory_copy.95.h"

void test(void) {
    static m14_memoryX5FcopyX2E95Instance instance;
    m14_memoryX5FcopyX2E95Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.95.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FcopyX2E95Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FcopyX2E95FreeInstance(&instance);
}
