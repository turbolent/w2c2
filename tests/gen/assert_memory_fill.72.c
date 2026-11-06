#include "test.h"
#include "test_memory_fill.72.h"

void test(void) {
    static m14_memoryX5FfillX2E72Instance instance;
    m14_memoryX5FfillX2E72Instantiate(&instance, resolveTestImports);
    printStart("memory_fill.72.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FfillX2E72Export3_run(&instance, 65280u, 37u, 512u), trapMemoryOutOfBounds, "run(65280u, 37u, 512u)");
#endif
    assertEqualU32(
        m14_memoryX5FfillX2E72Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
    m14_memoryX5FfillX2E72FreeInstance(&instance);
}
