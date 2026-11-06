#include "test.h"
#include "test_unreachable.0.h"

void test(void) {
    static m13_unreachableX2E0Instance instance;
    m13_unreachableX2E0Instantiate(&instance, resolveTestImports);
    printStart("unreachable.0.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export8_typeX2Di32(&instance), trapUnreachable, "type-i32()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export8_typeX2Di64(&instance), trapUnreachable, "type-i64()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export8_typeX2Df32(&instance), trapUnreachable, "type-f32()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export8_typeX2Df64(&instance), trapUnreachable, "type-f64()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export13_asX2DfuncX2Dfirst(&instance), trapUnreachable, "as-func-first()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export11_asX2DfuncX2Dmid(&instance), trapUnreachable, "as-func-mid()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export12_asX2DfuncX2Dlast(&instance), trapUnreachable, "as-func-last()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export13_asX2DfuncX2Dvalue(&instance), trapUnreachable, "as-func-value()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export14_asX2DblockX2Dfirst(&instance), trapUnreachable, "as-block-first()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export12_asX2DblockX2Dmid(&instance), trapUnreachable, "as-block-mid()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export13_asX2DblockX2Dlast(&instance), trapUnreachable, "as-block-last()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export14_asX2DblockX2Dvalue(&instance), trapUnreachable, "as-block-value()");
#endif
    assertEqualU32(
        m13_unreachableX2E0Export14_asX2DblockX2Dbroke(&instance),
        1u,
        "as-block-broke()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export13_asX2DloopX2Dfirst(&instance), trapUnreachable, "as-loop-first()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export11_asX2DloopX2Dmid(&instance), trapUnreachable, "as-loop-mid()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export12_asX2DloopX2Dlast(&instance), trapUnreachable, "as-loop-last()");
#endif
    assertEqualU32(
        m13_unreachableX2E0Export13_asX2DloopX2Dbroke(&instance),
        1u,
        "as-loop-broke()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export11_asX2DbrX2Dvalue(&instance), trapUnreachable, "as-br-value()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export13_asX2DbrX5FifX2Dcond(&instance), trapUnreachable, "as-br_if-cond()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export14_asX2DbrX5FifX2Dvalue(&instance), trapUnreachable, "as-br_if-value()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export19_asX2DbrX5FifX2DvalueX2Dcond(&instance), trapUnreachable, "as-br_if-value-cond()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export17_asX2DbrX5FtableX2Dindex(&instance), trapUnreachable, "as-br_table-index()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export17_asX2DbrX5FtableX2Dvalue(&instance), trapUnreachable, "as-br_table-value()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export19_asX2DbrX5FtableX2DvalueX2D2(&instance), trapUnreachable, "as-br_table-value-2()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export23_asX2DbrX5FtableX2DvalueX2Dindex(&instance), trapUnreachable, "as-br_table-value-index()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export27_asX2DbrX5FtableX2DvalueX2DandX2Dindex(&instance), trapUnreachable, "as-br_table-value-and-index()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export15_asX2DreturnX2Dvalue(&instance), trapUnreachable, "as-return-value()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export10_asX2DifX2Dcond(&instance), trapUnreachable, "as-if-cond()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export10_asX2DifX2Dthen(&instance, 1u, 6u), trapUnreachable, "as-if-then(1u, 6u)");
#endif
    assertEqualU32(
        m13_unreachableX2E0Export10_asX2DifX2Dthen(&instance, 0u, 6u),
        6u,
        "as-if-then(0u, 6u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export10_asX2DifX2Delse(&instance, 0u, 6u), trapUnreachable, "as-if-else(0u, 6u)");
#endif
    assertEqualU32(
        m13_unreachableX2E0Export10_asX2DifX2Delse(&instance, 1u, 6u),
        6u,
        "as-if-else(1u, 6u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export18_asX2DifX2DthenX2DnoX2Delse(&instance, 1u, 6u), trapUnreachable, "as-if-then-no-else(1u, 6u)");
#endif
    assertEqualU32(
        m13_unreachableX2E0Export18_asX2DifX2DthenX2DnoX2Delse(&instance, 0u, 6u),
        6u,
        "as-if-then-no-else(0u, 6u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export15_asX2DselectX2Dfirst(&instance, 0u, 6u), trapUnreachable, "as-select-first(0u, 6u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export15_asX2DselectX2Dfirst(&instance, 1u, 6u), trapUnreachable, "as-select-first(1u, 6u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export16_asX2DselectX2Dsecond(&instance, 0u, 6u), trapUnreachable, "as-select-second(0u, 6u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export16_asX2DselectX2Dsecond(&instance, 1u, 6u), trapUnreachable, "as-select-second(1u, 6u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export14_asX2DselectX2Dcond(&instance), trapUnreachable, "as-select-cond()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export13_asX2DcallX2Dfirst(&instance), trapUnreachable, "as-call-first()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export11_asX2DcallX2Dmid(&instance), trapUnreachable, "as-call-mid()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export12_asX2DcallX2Dlast(&instance), trapUnreachable, "as-call-last()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export21_asX2DcallX5FindirectX2Dfunc(&instance), trapUnreachable, "as-call_indirect-func()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export22_asX2DcallX5FindirectX2Dfirst(&instance), trapUnreachable, "as-call_indirect-first()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export20_asX2DcallX5FindirectX2Dmid(&instance), trapUnreachable, "as-call_indirect-mid()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export21_asX2DcallX5FindirectX2Dlast(&instance), trapUnreachable, "as-call_indirect-last()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export18_asX2DlocalX2EsetX2Dvalue(&instance), trapUnreachable, "as-local.set-value()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export18_asX2DlocalX2EteeX2Dvalue(&instance), trapUnreachable, "as-local.tee-value()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export19_asX2DglobalX2EsetX2Dvalue(&instance), trapUnreachable, "as-global.set-value()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export15_asX2DloadX2Daddress(&instance), trapUnreachable, "as-load-address()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export16_asX2DloadNX2Daddress(&instance), trapUnreachable, "as-loadN-address()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export16_asX2DstoreX2Daddress(&instance), trapUnreachable, "as-store-address()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export14_asX2DstoreX2Dvalue(&instance), trapUnreachable, "as-store-value()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export17_asX2DstoreNX2Daddress(&instance), trapUnreachable, "as-storeN-address()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export15_asX2DstoreNX2Dvalue(&instance), trapUnreachable, "as-storeN-value()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export16_asX2DunaryX2Doperand(&instance), trapUnreachable, "as-unary-operand()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export14_asX2DbinaryX2Dleft(&instance), trapUnreachable, "as-binary-left()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export15_asX2DbinaryX2Dright(&instance), trapUnreachable, "as-binary-right()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export15_asX2DtestX2Doperand(&instance), trapUnreachable, "as-test-operand()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export15_asX2DcompareX2Dleft(&instance), trapUnreachable, "as-compare-left()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export16_asX2DcompareX2Dright(&instance), trapUnreachable, "as-compare-right()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export18_asX2DconvertX2Doperand(&instance), trapUnreachable, "as-convert-operand()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_unreachableX2E0Export19_asX2DmemoryX2EgrowX2Dsize(&instance), trapUnreachable, "as-memory.grow-size()");
#endif
    m13_unreachableX2E0FreeInstance(&instance);
}
