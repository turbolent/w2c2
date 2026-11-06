#include "test.h"
#include "test_unreached-valid.0.h"

void test(void) {
    static m17_unreachedX2DvalidX2E0Instance instance;
    m17_unreachedX2DvalidX2E0Instantiate(&instance, resolveTestImports);
    printStart("unreached-valid.0.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m17_unreachedX2DvalidX2E0Export16_selectX2DtrapX2Dleft(&instance, 1u), trapUnreachable, "select-trap-left(1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m17_unreachedX2DvalidX2E0Export16_selectX2DtrapX2Dleft(&instance, 0u), trapUnreachable, "select-trap-left(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m17_unreachedX2DvalidX2E0Export17_selectX2DtrapX2Dright(&instance, 1u), trapUnreachable, "select-trap-right(1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m17_unreachedX2DvalidX2E0Export17_selectX2DtrapX2Dright(&instance, 0u), trapUnreachable, "select-trap-right(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m17_unreachedX2DvalidX2E0Export25_selectX5FunreachedX5FresultX5F1(&instance), trapUnreachable, "select_unreached_result_1()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m17_unreachedX2DvalidX2E0Export25_selectX5FunreachedX5FresultX5F2(&instance), trapUnreachable, "select_unreached_result_2()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m17_unreachedX2DvalidX2E0Export15_unreachableX2Dnum(&instance), trapUnreachable, "unreachable-num()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m17_unreachedX2DvalidX2E0Export15_unreachableX2Dref(&instance), trapUnreachable, "unreachable-ref()");
#endif
    m17_unreachedX2DvalidX2E0FreeInstance(&instance);
}
