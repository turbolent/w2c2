#include "test.h"
#include "test_memory_init.13.h"

void test(void) {
    static m14_memoryX5FinitX2E13Instance instance;
    m14_memoryX5FinitX2E13Instantiate(&instance, resolveTestImports);
    printStart("memory_init.13.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E13Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FinitX2E13FreeInstance(&instance);
}
