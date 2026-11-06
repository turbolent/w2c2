#include "test.h"
#include "test_memory_init.88.h"

void test(void) {
    static m14_memoryX5FinitX2E88Instance instance;
    m14_memoryX5FinitX2E88Instantiate(&instance, resolveTestImports);
    printStart("memory_init.88.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m14_memoryX5FinitX2E88Export3_run(&instance, 65528u, 4294967040u), trapMemoryOutOfBounds, "run(65528u, 4294967040u)");
#endif
    assertEqualU32(
        m14_memoryX5FinitX2E88Export10_checkRange(&instance, 0u, 1u, 0u),
        4294967295u,
        "checkRange(0u, 1u, 0u)"
    );
    m14_memoryX5FinitX2E88FreeInstance(&instance);
}
