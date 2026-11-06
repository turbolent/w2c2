#include "test.h"
#include "test_memory_init.86.h"

void test(void) {
    static m14_memoryX5FinitX2E86Instance instance;
    m14_memoryX5FinitX2E86Instantiate(&instance, resolveTestImports);
    printStart("memory_init.86.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E86Export3_run(&instance, 65472u, 30u), trapMemoryOutOfBounds, "run(65472u, 30u)");
#endif
    assertEqualU32(
        m14_memoryX5FinitX2E86Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
    m14_memoryX5FinitX2E86FreeInstance(&instance);
}
