#include "test.h"
#include "test_memory_fill.73.h"

void test(void) {
    static m14_memoryX5FfillX2E73Instance instance;
    m14_memoryX5FfillX2E73Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.73.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FfillX2E73Export3_run(&instance, 65279u, 37u, 514u), trapMemoryOutOfBounds, "run(65279u, 37u, 514u)");
#endif
    assertEqualU32(
        m14_memoryX5FfillX2E73Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
    m14_memoryX5FfillX2E73FreeInstance(&instance);
}
