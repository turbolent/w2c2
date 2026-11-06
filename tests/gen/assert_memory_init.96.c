#include "test.h"
#include "test_memory_init.96.h"

void test(void) {
    static m14_memoryX5FinitX2E96Instance instance;
    m14_memoryX5FinitX2E96Instantiate(&instance, resolveTestImports);
    printStart("memory_init.96.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E96Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FinitX2E96FreeInstance(&instance);
}
