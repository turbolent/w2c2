#include "test.h"
#include "test_traps_regression.1.h"

void test(void) {
    static m18_trapsX5FregressionX2E1Instance instance;
    m18_trapsX5FregressionX2E1Instantiate(&instance, resolveTestImports);
    printStart("traps_regression.1.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export12_orderedX2Dload(&instance, 65536u), trapMemoryOutOfBounds, "ordered-load(65536u)");
#endif
    assertEqualU32(
        *m18_trapsX5FregressionX2E1Export5_state(&instance),
        1u,
        "get state"
    );
    assertEqualU32(
        m18_trapsX5FregressionX2E1Export4_read(&instance, 0u),
        42u,
        "read(0u)"
    );
    (void)(m18_trapsX5FregressionX2E1Export12_orderedX2Dload(&instance, 0u));
    assertEqualU32(
        *m18_trapsX5FregressionX2E1Export5_state(&instance),
        2u,
        "get state"
    );
    assertEqualU32(
        m18_trapsX5FregressionX2E1Export4_read(&instance, 0u),
        99u,
        "read(0u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export16_overwrittenX2Dload(&instance, 65536u), trapMemoryOutOfBounds, "overwritten-load(65536u)");
#endif
    assertEqualU32(
        m18_trapsX5FregressionX2E1Export16_overwrittenX2Dload(&instance, 0u),
        7u,
        "overwritten-load(0u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export14_identicalX2Darms(&instance, 65536u), trapMemoryOutOfBounds, "identical-arms(65536u)");
#endif
    assertEqualU32(
        m18_trapsX5FregressionX2E1Export14_identicalX2Darms(&instance, 0u),
        7u,
        "identical-arms(0u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export11_offsetX2Dload(&instance, 1u), trapMemoryOutOfBounds, "offset-load(1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export12_offsetX2Dstore(&instance, 1u), trapMemoryOutOfBounds, "offset-store(1u)");
#endif
    assertEqualU32(
        m18_trapsX5FregressionX2E1Export4_read(&instance, 0u),
        99u,
        "read(0u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export13_partialX2Dstore(&instance), trapMemoryOutOfBounds, "partial-store()");
#endif
    assertEqualU32(
        m18_trapsX5FregressionX2E1Export4_read(&instance, 65532u),
        1145258561u,
        "read(65532u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export14_divisionX2Dfirst(&instance, 0u), trapDivByZero, "division-first(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export12_memoryX2Dfirst(&instance, 0u), trapMemoryOutOfBounds, "memory-first(0u)");
#endif
    (void)(m18_trapsX5FregressionX2E1Export4_fill(&instance, 65536u, 0u));
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export4_fill(&instance, 65537u, 0u), trapMemoryOutOfBounds, "fill(65537u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export4_fill(&instance, 65534u, 4u), trapMemoryOutOfBounds, "fill(65534u, 4u)");
#endif
    assertEqualU32(
        m18_trapsX5FregressionX2E1Export4_read(&instance, 65532u),
        1145258561u,
        "read(65532u)"
    );
    (void)(m18_trapsX5FregressionX2E1Export4_copy(&instance, 65536u, 65536u, 0u));
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export4_copy(&instance, 65537u, 0u, 0u), trapMemoryOutOfBounds, "copy(65537u, 0u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export4_copy(&instance, 0u, 65537u, 0u), trapMemoryOutOfBounds, "copy(0u, 65537u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export4_copy(&instance, 0u, 65534u, 4u), trapMemoryOutOfBounds, "copy(0u, 65534u, 4u)");
#endif
    assertEqualU32(
        m18_trapsX5FregressionX2E1Export4_read(&instance, 0u),
        99u,
        "read(0u)"
    );
    (void)(m18_trapsX5FregressionX2E1Export4_init(&instance, 65536u, 2u, 0u));
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export4_init(&instance, 65537u, 0u, 0u), trapMemoryOutOfBounds, "init(65537u, 0u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export4_init(&instance, 0u, 3u, 0u), trapMemoryOutOfBounds, "init(0u, 3u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_trapsX5FregressionX2E1Export4_init(&instance, 0u, 1u, 2u), trapMemoryOutOfBounds, "init(0u, 1u, 2u)");
#endif
    assertEqualU32(
        m18_trapsX5FregressionX2E1Export4_read(&instance, 0u),
        99u,
        "read(0u)"
    );
    m18_trapsX5FregressionX2E1FreeInstance(&instance);
}
