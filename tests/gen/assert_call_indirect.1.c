#include "test.h"
#include "test_call_indirect.1.h"

void test(void) {
    static m15_callX5FindirectX2E1Instance instance;
    m15_callX5FindirectX2E1Instantiate(&instance, resolveTestImports);
    printStart("call_indirect.1.wasm");
    assertEqualU32(
        m15_callX5FindirectX2E1Export6_callX2D1(&instance, 2u, 3u, 0u),
        5u,
        "call-1(2u, 3u, 0u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E1Export6_callX2D1(&instance, 2u, 3u, 1u),
        4294967295u,
        "call-1(2u, 3u, 1u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m15_callX5FindirectX2E1Export6_callX2D1(&instance, 2u, 3u, 2u), trapTableOutOfBounds, "call-1(2u, 3u, 2u)");
#endif
    assertEqualU32(
        m15_callX5FindirectX2E1Export6_callX2D2(&instance, 2u, 3u, 0u),
        6u,
        "call-2(2u, 3u, 0u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E1Export6_callX2D2(&instance, 2u, 3u, 1u),
        0u,
        "call-2(2u, 3u, 1u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E1Export6_callX2D2(&instance, 2u, 3u, 2u),
        2u,
        "call-2(2u, 3u, 2u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m15_callX5FindirectX2E1Export6_callX2D2(&instance, 2u, 3u, 3u), trapTableOutOfBounds, "call-2(2u, 3u, 3u)");
#endif
    assertEqualU32(
        m15_callX5FindirectX2E1Export6_callX2D3(&instance, 2u, 3u, 0u),
        4294967295u,
        "call-3(2u, 3u, 0u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E1Export6_callX2D3(&instance, 2u, 3u, 1u),
        6u,
        "call-3(2u, 3u, 1u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m15_callX5FindirectX2E1Export6_callX2D3(&instance, 2u, 3u, 2u), trapUninitializedElement, "call-3(2u, 3u, 2u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m15_callX5FindirectX2E1Export6_callX2D3(&instance, 2u, 3u, 3u), trapIndirectCallTypeMismatch, "call-3(2u, 3u, 3u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m15_callX5FindirectX2E1Export6_callX2D3(&instance, 2u, 3u, 4u), trapTableOutOfBounds, "call-3(2u, 3u, 4u)");
#endif
    m15_callX5FindirectX2E1FreeInstance(&instance);
}
