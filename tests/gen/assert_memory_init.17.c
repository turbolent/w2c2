#include "test.h"
#include "test_memory_init.17.h"

void test(void) {
    static m14_memoryX5FinitX2E17Instance instance;
    m14_memoryX5FinitX2E17Instantiate(&instance, resolveTestImports);
    printStart("memory_init.17.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E17Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FinitX2E17FreeInstance(&instance);
}
