#include "test.h"
#include "test_memory_trap.0.h"

void test(void) {
    static m13_memoryX5FtrapX2E0Instance instance;
    m13_memoryX5FtrapX2E0Instantiate(&instance, resolveTestImports);
    printStart("memory_trap.0.wasm");
    (void)(m13_memoryX5FtrapX2E0Export5_store(&instance, 4294967292u, 42u));
    assertEqualU32(
        m13_memoryX5FtrapX2E0Export4_load(&instance, 4294967292u),
        42u,
        "load(4294967292u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E0Export5_store(&instance, 4294967293u, 305419896u), trapMemoryOutOfBounds, "store(4294967293u, 305419896u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E0Export4_load(&instance, 4294967293u), trapMemoryOutOfBounds, "load(4294967293u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E0Export5_store(&instance, 4294967294u, 13u), trapMemoryOutOfBounds, "store(4294967294u, 13u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E0Export4_load(&instance, 4294967294u), trapMemoryOutOfBounds, "load(4294967294u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E0Export5_store(&instance, 4294967295u, 13u), trapMemoryOutOfBounds, "store(4294967295u, 13u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E0Export4_load(&instance, 4294967295u), trapMemoryOutOfBounds, "load(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E0Export5_store(&instance, 0u, 13u), trapMemoryOutOfBounds, "store(0u, 13u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E0Export4_load(&instance, 0u), trapMemoryOutOfBounds, "load(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E0Export5_store(&instance, 2147483648u, 13u), trapMemoryOutOfBounds, "store(2147483648u, 13u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E0Export4_load(&instance, 2147483648u), trapMemoryOutOfBounds, "load(2147483648u)");
#endif
    assertEqualU32(
        m13_memoryX5FtrapX2E0Export11_memoryX2Egrow(&instance, 65537u),
        4294967295u,
        "memory.grow(65537u)"
    );
    m13_memoryX5FtrapX2E0FreeInstance(&instance);
}
