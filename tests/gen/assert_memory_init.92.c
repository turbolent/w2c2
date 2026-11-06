#include "test.h"
#include "test_memory_init.92.h"

void test(void) {
    static m14_memoryX5FinitX2E92Instance instance;
    m14_memoryX5FinitX2E92Instantiate(&instance, resolveTestImports);
    printStart("memory_init.92.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E92Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FinitX2E92FreeInstance(&instance);
}
