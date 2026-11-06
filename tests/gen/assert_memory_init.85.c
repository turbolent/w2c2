#include "test.h"
#include "test_memory_init.85.h"

void test(void) {
    static m14_memoryX5FinitX2E85Instance instance;
    m14_memoryX5FinitX2E85Instantiate(&instance, resolveTestImports);
    printStart("memory_init.85.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E85Export3_run(&instance, 65527u, 16u), trapMemoryOutOfBounds, "run(65527u, 16u)");
#endif
    assertEqualU32(
        m14_memoryX5FinitX2E85Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
    m14_memoryX5FinitX2E85FreeInstance(&instance);
}
