#include "test.h"
#include "test_memory_init.12.h"

void test(void) {
    static m14_memoryX5FinitX2E12Instance instance;
    m14_memoryX5FinitX2E12Instantiate(&instance, resolveTestImports);
    printStart("memory_init.12.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E12Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FinitX2E12FreeInstance(&instance);
}
