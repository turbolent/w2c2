#include "test.h"
#include "test_memory_init.89.h"

void test(void) {
    static m14_memoryX5FinitX2E89Instance instance;
    m14_memoryX5FinitX2E89Instantiate(&instance, resolveTestImports);
    printStart("memory_init.89.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E89Export3_run(&instance, 0u, 4294967292u), trapMemoryOutOfBounds, "run(0u, 4294967292u)");
#endif
    assertEqualU32(
        m14_memoryX5FinitX2E89Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
    m14_memoryX5FinitX2E89FreeInstance(&instance);
}
