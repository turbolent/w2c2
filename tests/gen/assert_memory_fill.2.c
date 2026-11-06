#include "test.h"
#include "test_memory_fill.2.h"

void test(void) {
    static m13_memoryX5FfillX2E2Instance instance;
    m13_memoryX5FfillX2E2Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.2.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FfillX2E2Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m13_memoryX5FfillX2E2FreeInstance(&instance);
}
