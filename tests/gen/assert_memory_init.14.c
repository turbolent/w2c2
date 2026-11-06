#include "test.h"
#include "test_memory_init.14.h"

void test(void) {
    static m14_memoryX5FinitX2E14Instance instance;
    m14_memoryX5FinitX2E14Instantiate(&instance, resolveTestImports);
    printStart("memory_init.14.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E14Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m14_memoryX5FinitX2E14FreeInstance(&instance);
}
