#include "test.h"
#include "test_memory_fill.5.h"

void test(void) {
    static m13_memoryX5FfillX2E5Instance instance;
    m13_memoryX5FfillX2E5Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.5.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FfillX2E5Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m13_memoryX5FfillX2E5FreeInstance(&instance);
}
