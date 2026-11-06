#include "test.h"
#include "test_memory_init.94.h"

void test(void) {
    static m14_memoryX5FinitX2E94Instance instance;
    m14_memoryX5FinitX2E94Instantiate(&instance, resolveTestImports);
    printStart("memory_init.94.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E94Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FinitX2E94FreeInstance(&instance);
}
