
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_nop.0.h"

void test() {
    nop0Instance instance;
    nop0Instantiate(&instance, resolveTestImports);
    printStart("nop.0.wasm");
    assertEqualU32(
        nop0_asX2DfuncX2Dfirst(&instance),
        1u,
        "as-func-first()"
    );
    assertEqualU32(
        nop0_asX2DfuncX2Dmid(&instance),
        2u,
        "as-func-mid()"
    );
    assertEqualU32(
        nop0_asX2DfuncX2Dlast(&instance),
        3u,
        "as-func-last()"
    );
    assertEqualU32(
        nop0_asX2DfuncX2Deverywhere(&instance),
        4u,
        "as-func-everywhere()"
    );
    nop0_asX2DdropX2Dfirst(&instance, 0u);
    nop0_asX2DdropX2Dlast(&instance, 0u);
    nop0_asX2DdropX2Deverywhere(&instance, 0u);
    assertEqualU32(
        nop0_asX2DselectX2Dfirst(&instance, 3u),
        3u,
        "as-select-first(3u)"
    );
    assertEqualU32(
        nop0_asX2DselectX2Dmid1(&instance, 3u),
        3u,
        "as-select-mid1(3u)"
    );
    assertEqualU32(
        nop0_asX2DselectX2Dmid2(&instance, 3u),
        3u,
        "as-select-mid2(3u)"
    );
    assertEqualU32(
        nop0_asX2DselectX2Dlast(&instance, 3u),
        3u,
        "as-select-last(3u)"
    );
    assertEqualU32(
        nop0_asX2DselectX2Deverywhere(&instance, 3u),
        3u,
        "as-select-everywhere(3u)"
    );
    assertEqualU32(
        nop0_asX2DblockX2Dfirst(&instance),
        2u,
        "as-block-first()"
    );
    assertEqualU32(
        nop0_asX2DblockX2Dmid(&instance),
        2u,
        "as-block-mid()"
    );
    assertEqualU32(
        nop0_asX2DblockX2Dlast(&instance),
        3u,
        "as-block-last()"
    );
    assertEqualU32(
        nop0_asX2DblockX2Deverywhere(&instance),
        4u,
        "as-block-everywhere()"
    );
    assertEqualU32(
        nop0_asX2DloopX2Dfirst(&instance),
        2u,
        "as-loop-first()"
    );
    assertEqualU32(
        nop0_asX2DloopX2Dmid(&instance),
        2u,
        "as-loop-mid()"
    );
    assertEqualU32(
        nop0_asX2DloopX2Dlast(&instance),
        3u,
        "as-loop-last()"
    );
    assertEqualU32(
        nop0_asX2DloopX2Deverywhere(&instance),
        4u,
        "as-loop-everywhere()"
    );
    nop0_asX2DifX2Dcondition(&instance, 0u);
    nop0_asX2DifX2Dcondition(&instance, 4294967295u);
    nop0_asX2DifX2Dthen(&instance, 0u);
    nop0_asX2DifX2Dthen(&instance, 4u);
    nop0_asX2DifX2Delse(&instance, 0u);
    nop0_asX2DifX2Delse(&instance, 3u);
    assertEqualU32(
        nop0_asX2DbrX2Dfirst(&instance, 5u),
        5u,
        "as-br-first(5u)"
    );
    assertEqualU32(
        nop0_asX2DbrX2Dlast(&instance, 6u),
        6u,
        "as-br-last(6u)"
    );
    assertEqualU32(
        nop0_asX2DbrX2Deverywhere(&instance, 7u),
        7u,
        "as-br-everywhere(7u)"
    );
    assertEqualU32(
        nop0_asX2DbrX5FifX2Dfirst(&instance, 4u),
        4u,
        "as-br_if-first(4u)"
    );
    assertEqualU32(
        nop0_asX2DbrX5FifX2Dmid(&instance, 5u),
        5u,
        "as-br_if-mid(5u)"
    );
    assertEqualU32(
        nop0_asX2DbrX5FifX2Dlast(&instance, 6u),
        6u,
        "as-br_if-last(6u)"
    );
    assertEqualU32(
        nop0_asX2DbrX5FifX2Deverywhere(&instance, 7u),
        7u,
        "as-br_if-everywhere(7u)"
    );
    assertEqualU32(
        nop0_asX2DbrX5FtableX2Dfirst(&instance, 4u),
        4u,
        "as-br_table-first(4u)"
    );
    assertEqualU32(
        nop0_asX2DbrX5FtableX2Dmid(&instance, 5u),
        5u,
        "as-br_table-mid(5u)"
    );
    assertEqualU32(
        nop0_asX2DbrX5FtableX2Dlast(&instance, 6u),
        6u,
        "as-br_table-last(6u)"
    );
    assertEqualU32(
        nop0_asX2DbrX5FtableX2Deverywhere(&instance, 7u),
        7u,
        "as-br_table-everywhere(7u)"
    );
    assertEqualU32(
        nop0_asX2DreturnX2Dfirst(&instance, 5u),
        5u,
        "as-return-first(5u)"
    );
    assertEqualU32(
        nop0_asX2DreturnX2Dlast(&instance, 6u),
        6u,
        "as-return-last(6u)"
    );
    assertEqualU32(
        nop0_asX2DreturnX2Deverywhere(&instance, 7u),
        7u,
        "as-return-everywhere(7u)"
    );
    assertEqualU32(
        nop0_asX2DcallX2Dfirst(&instance, 3u, 1u, 2u),
        2u,
        "as-call-first(3u, 1u, 2u)"
    );
    assertEqualU32(
        nop0_asX2DcallX2Dmid1(&instance, 3u, 1u, 2u),
        2u,
        "as-call-mid1(3u, 1u, 2u)"
    );
    assertEqualU32(
        nop0_asX2DcallX2Dmid2(&instance, 0u, 3u, 1u),
        2u,
        "as-call-mid2(0u, 3u, 1u)"
    );
    assertEqualU32(
        nop0_asX2DcallX2Dlast(&instance, 10u, 9u, 4294967295u),
        20u,
        "as-call-last(10u, 9u, 4294967295u)"
    );
    assertEqualU32(
        nop0_asX2DcallX2Deverywhere(&instance, 2u, 1u, 5u),
        4294967294u,
        "as-call-everywhere(2u, 1u, 5u)"
    );
    assertEqualU32(
        nop0_asX2DunaryX2Dfirst(&instance, 30u),
        1u,
        "as-unary-first(30u)"
    );
    assertEqualU32(
        nop0_asX2DunaryX2Dlast(&instance, 30u),
        1u,
        "as-unary-last(30u)"
    );
    assertEqualU32(
        nop0_asX2DunaryX2Deverywhere(&instance, 12u),
        2u,
        "as-unary-everywhere(12u)"
    );
    assertEqualU32(
        nop0_asX2DbinaryX2Dfirst(&instance, 3u),
        6u,
        "as-binary-first(3u)"
    );
    assertEqualU32(
        nop0_asX2DbinaryX2Dmid(&instance, 3u),
        6u,
        "as-binary-mid(3u)"
    );
    assertEqualU32(
        nop0_asX2DbinaryX2Dlast(&instance, 3u),
        6u,
        "as-binary-last(3u)"
    );
    assertEqualU32(
        nop0_asX2DbinaryX2Deverywhere(&instance, 3u),
        6u,
        "as-binary-everywhere(3u)"
    );
    assertEqualU32(
        nop0_asX2DtestX2Dfirst(&instance, 0u),
        1u,
        "as-test-first(0u)"
    );
    assertEqualU32(
        nop0_asX2DtestX2Dlast(&instance, 0u),
        1u,
        "as-test-last(0u)"
    );
    assertEqualU32(
        nop0_asX2DtestX2Deverywhere(&instance, 0u),
        1u,
        "as-test-everywhere(0u)"
    );
    assertEqualU32(
        nop0_asX2DcompareX2Dfirst(&instance, 3u),
        0u,
        "as-compare-first(3u)"
    );
    assertEqualU32(
        nop0_asX2DcompareX2Dmid(&instance, 3u),
        0u,
        "as-compare-mid(3u)"
    );
    assertEqualU32(
        nop0_asX2DcompareX2Dlast(&instance, 3u),
        0u,
        "as-compare-last(3u)"
    );
    assertEqualU32(
        nop0_asX2DcompareX2Deverywhere(&instance, 3u),
        1u,
        "as-compare-everywhere(3u)"
    );
    assertEqualU32(
        nop0_asX2DmemoryX2EgrowX2Dfirst(&instance, 0u),
        1u,
        "as-memory.grow-first(0u)"
    );
    assertEqualU32(
        nop0_asX2DmemoryX2EgrowX2Dlast(&instance, 2u),
        1u,
        "as-memory.grow-last(2u)"
    );
    assertEqualU32(
        nop0_asX2DmemoryX2EgrowX2Deverywhere(&instance, 12u),
        3u,
        "as-memory.grow-everywhere(12u)"
    );
    assertEqualU32(
        nop0_asX2DcallX5FindirectX2Dfirst(&instance),
        1u,
        "as-call_indirect-first()"
    );
    assertEqualU32(
        nop0_asX2DcallX5FindirectX2Dmid1(&instance),
        1u,
        "as-call_indirect-mid1()"
    );
    assertEqualU32(
        nop0_asX2DcallX5FindirectX2Dmid2(&instance),
        1u,
        "as-call_indirect-mid2()"
    );
    assertEqualU32(
        nop0_asX2DcallX5FindirectX2Dlast(&instance),
        1u,
        "as-call_indirect-last()"
    );
    assertEqualU32(
        nop0_asX2DcallX5FindirectX2Deverywhere(&instance),
        1u,
        "as-call_indirect-everywhere()"
    );
    assertEqualU32(
        nop0_asX2DlocalX2EsetX2Dfirst(&instance, 1u),
        2u,
        "as-local.set-first(1u)"
    );
    assertEqualU32(
        nop0_asX2DlocalX2EsetX2Dlast(&instance, 1u),
        2u,
        "as-local.set-last(1u)"
    );
    assertEqualU32(
        nop0_asX2DlocalX2EsetX2Deverywhere(&instance, 1u),
        2u,
        "as-local.set-everywhere(1u)"
    );
    assertEqualU32(
        nop0_asX2DlocalX2EteeX2Dfirst(&instance, 1u),
        2u,
        "as-local.tee-first(1u)"
    );
    assertEqualU32(
        nop0_asX2DlocalX2EteeX2Dlast(&instance, 1u),
        2u,
        "as-local.tee-last(1u)"
    );
    assertEqualU32(
        nop0_asX2DlocalX2EteeX2Deverywhere(&instance, 1u),
        2u,
        "as-local.tee-everywhere(1u)"
    );
    assertEqualU32(
        nop0_asX2DglobalX2EsetX2Dfirst(&instance),
        2u,
        "as-global.set-first()"
    );
    assertEqualU32(
        nop0_asX2DglobalX2EsetX2Dlast(&instance),
        2u,
        "as-global.set-last()"
    );
    assertEqualU32(
        nop0_asX2DglobalX2EsetX2Deverywhere(&instance),
        2u,
        "as-global.set-everywhere()"
    );
    assertEqualU32(
        nop0_asX2DloadX2Dfirst(&instance, 100u),
        0u,
        "as-load-first(100u)"
    );
    assertEqualU32(
        nop0_asX2DloadX2Dlast(&instance, 100u),
        0u,
        "as-load-last(100u)"
    );
    assertEqualU32(
        nop0_asX2DloadX2Deverywhere(&instance, 100u),
        0u,
        "as-load-everywhere(100u)"
    );
    nop0_asX2DstoreX2Dfirst(&instance, 0u, 1u);
    nop0_asX2DstoreX2Dmid(&instance, 0u, 2u);
    nop0_asX2DstoreX2Dlast(&instance, 0u, 3u);
    nop0_asX2DstoreX2Deverywhere(&instance, 0u, 4u);
}
