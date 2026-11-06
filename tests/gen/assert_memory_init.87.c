#include "test.h"
#include "test_memory_init.87.h"

void test(void) {
    static m14_memoryX5FinitX2E87Instance instance;
    m14_memoryX5FinitX2E87Instantiate(&instance, resolveTestImports);
    printStart("memory_init.87.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E87Export3_run(&instance, 65473u, 31u), trapMemoryOutOfBounds, "run(65473u, 31u)");
#endif
    assertEqualU32(
        m14_memoryX5FinitX2E87Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
    m14_memoryX5FinitX2E87FreeInstance(&instance);
}
