#include "test.h"
#include "test_memory_init.7.h"

void test(void) {
    static m13_memoryX5FinitX2E7Instance instance;
    m13_memoryX5FinitX2E7Instantiate(&instance, resolveTestImports);
    printStart("memory_init.7.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FinitX2E7Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m13_memoryX5FinitX2E7FreeInstance(&instance);
}
