#include "test.h"
#include "test_memory_fill.74.h"

void test(void) {
    static m14_memoryX5FfillX2E74Instance instance;
    m14_memoryX5FfillX2E74Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.74.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FfillX2E74Export3_run(&instance, 65279u, 37u, 4294967295u), trapMemoryOutOfBounds, "run(65279u, 37u, 4294967295u)");
#endif
    assertEqualU32(
        m14_memoryX5FfillX2E74Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
    m14_memoryX5FfillX2E74FreeInstance(&instance);
}
