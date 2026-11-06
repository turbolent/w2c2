#include "test.h"
#include "test_memory_fill.1.h"

void test(void) {
    static m13_memoryX5FfillX2E1Instance instance;
    m13_memoryX5FfillX2E1Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.1.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FfillX2E1Export4_test(&instance), trapMemoryOutOfBounds, "test()");
#endif
    m13_memoryX5FfillX2E1FreeInstance(&instance);
}
