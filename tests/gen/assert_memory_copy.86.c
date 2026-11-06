#include "test.h"
#include "test_memory_copy.86.h"

void test(void) {
    static m14_memoryX5FcopyX2E86Instance instance;
    m14_memoryX5FcopyX2E86Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.86.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FcopyX2E86Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FcopyX2E86FreeInstance(&instance);
}
