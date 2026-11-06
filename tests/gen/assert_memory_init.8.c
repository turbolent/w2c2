#include "test.h"
#include "test_memory_init.8.h"

void test(void) {
    static m13_memoryX5FinitX2E8Instance instance;
    m13_memoryX5FinitX2E8Instantiate(&instance, resolveTestImports);
    printStart("memory_init.8.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FinitX2E8Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m13_memoryX5FinitX2E8FreeInstance(&instance);
}
