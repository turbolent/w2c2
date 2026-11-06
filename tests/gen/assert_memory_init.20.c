#include "test.h"
#include "test_memory_init.20.h"

void test(void) {
    static m14_memoryX5FinitX2E20Instance instance;
    m14_memoryX5FinitX2E20Instantiate(&instance, resolveTestImports);
    printStart("memory_init.20.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E20Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FinitX2E20FreeInstance(&instance);
}
