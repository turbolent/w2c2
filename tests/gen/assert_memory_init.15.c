#include "test.h"
#include "test_memory_init.15.h"

void test(void) {
    static m14_memoryX5FinitX2E15Instance instance;
    m14_memoryX5FinitX2E15Instantiate(&instance, resolveTestImports);
    printStart("memory_init.15.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E15Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FinitX2E15FreeInstance(&instance);
}
