
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_br_if.0.h"

void test() {
    brif0Instance instance;
    brif0Instantiate(&instance, resolveTestImports);
    printStart("br_if.0.wasm");
    brif0_typeX2Di32(&instance);
    brif0_typeX2Di64(&instance);
    brif0_typeX2Df32(&instance);
    brif0_typeX2Df64(&instance);
    assertEqualU32(
        brif0_typeX2Di32X2Dvalue(&instance),
        1u,
        "type-i32-value()"
    );
    assertEqualU64(
        brif0_typeX2Di64X2Dvalue(&instance),
        2ull,
        "type-i64-value()"
    );
    assertEqualF32(
        brif0_typeX2Df32X2Dvalue(&instance),
        3.0,
        "type-f32-value()"
    );
    assertEqualF64(
        brif0_typeX2Df64X2Dvalue(&instance),
        4.0,
        "type-f64-value()"
    );
    assertEqualU32(
        brif0_asX2DblockX2Dfirst(&instance, 0u),
        2u,
        "as-block-first(0u)"
    );
    assertEqualU32(
        brif0_asX2DblockX2Dfirst(&instance, 1u),
        3u,
        "as-block-first(1u)"
    );
    assertEqualU32(
        brif0_asX2DblockX2Dmid(&instance, 0u),
        2u,
        "as-block-mid(0u)"
    );
    assertEqualU32(
        brif0_asX2DblockX2Dmid(&instance, 1u),
        3u,
        "as-block-mid(1u)"
    );
    brif0_asX2DblockX2Dlast(&instance, 0u);
    brif0_asX2DblockX2Dlast(&instance, 1u);
    assertEqualU32(
        brif0_asX2DblockX2DfirstX2Dvalue(&instance, 0u),
        11u,
        "as-block-first-value(0u)"
    );
    assertEqualU32(
        brif0_asX2DblockX2DfirstX2Dvalue(&instance, 1u),
        10u,
        "as-block-first-value(1u)"
    );
    assertEqualU32(
        brif0_asX2DblockX2DmidX2Dvalue(&instance, 0u),
        21u,
        "as-block-mid-value(0u)"
    );
    assertEqualU32(
        brif0_asX2DblockX2DmidX2Dvalue(&instance, 1u),
        20u,
        "as-block-mid-value(1u)"
    );
    assertEqualU32(
        brif0_asX2DblockX2DlastX2Dvalue(&instance, 0u),
        11u,
        "as-block-last-value(0u)"
    );
    assertEqualU32(
        brif0_asX2DblockX2DlastX2Dvalue(&instance, 1u),
        11u,
        "as-block-last-value(1u)"
    );
    assertEqualU32(
        brif0_asX2DloopX2Dfirst(&instance, 0u),
        2u,
        "as-loop-first(0u)"
    );
    assertEqualU32(
        brif0_asX2DloopX2Dfirst(&instance, 1u),
        3u,
        "as-loop-first(1u)"
    );
    assertEqualU32(
        brif0_asX2DloopX2Dmid(&instance, 0u),
        2u,
        "as-loop-mid(0u)"
    );
    assertEqualU32(
        brif0_asX2DloopX2Dmid(&instance, 1u),
        4u,
        "as-loop-mid(1u)"
    );
    brif0_asX2DloopX2Dlast(&instance, 0u);
    brif0_asX2DloopX2Dlast(&instance, 1u);
    assertEqualU32(
        brif0_asX2DbrX2Dvalue(&instance),
        1u,
        "as-br-value()"
    );
    brif0_asX2DbrX5FifX2Dcond(&instance);
    assertEqualU32(
        brif0_asX2DbrX5FifX2Dvalue(&instance),
        1u,
        "as-br_if-value()"
    );
    assertEqualU32(
        brif0_asX2DbrX5FifX2DvalueX2Dcond(&instance, 0u),
        2u,
        "as-br_if-value-cond(0u)"
    );
    assertEqualU32(
        brif0_asX2DbrX5FifX2DvalueX2Dcond(&instance, 1u),
        1u,
        "as-br_if-value-cond(1u)"
    );
    brif0_asX2DbrX5FtableX2Dindex(&instance);
    assertEqualU32(
        brif0_asX2DbrX5FtableX2Dvalue(&instance),
        1u,
        "as-br_table-value()"
    );
    assertEqualU32(
        brif0_asX2DbrX5FtableX2DvalueX2Dindex(&instance),
        1u,
        "as-br_table-value-index()"
    );
    assertEqualU64(
        brif0_asX2DreturnX2Dvalue(&instance),
        1ull,
        "as-return-value()"
    );
    assertEqualU32(
        brif0_asX2DifX2Dcond(&instance, 0u),
        2u,
        "as-if-cond(0u)"
    );
    assertEqualU32(
        brif0_asX2DifX2Dcond(&instance, 1u),
        1u,
        "as-if-cond(1u)"
    );
    brif0_asX2DifX2Dthen(&instance, 0u, 0u);
    brif0_asX2DifX2Dthen(&instance, 4u, 0u);
    brif0_asX2DifX2Dthen(&instance, 0u, 1u);
    brif0_asX2DifX2Dthen(&instance, 4u, 1u);
    brif0_asX2DifX2Delse(&instance, 0u, 0u);
    brif0_asX2DifX2Delse(&instance, 3u, 0u);
    brif0_asX2DifX2Delse(&instance, 0u, 1u);
    brif0_asX2DifX2Delse(&instance, 3u, 1u);
    assertEqualU32(
        brif0_asX2DselectX2Dfirst(&instance, 0u),
        3u,
        "as-select-first(0u)"
    );
    assertEqualU32(
        brif0_asX2DselectX2Dfirst(&instance, 1u),
        3u,
        "as-select-first(1u)"
    );
    assertEqualU32(
        brif0_asX2DselectX2Dsecond(&instance, 0u),
        3u,
        "as-select-second(0u)"
    );
    assertEqualU32(
        brif0_asX2DselectX2Dsecond(&instance, 1u),
        3u,
        "as-select-second(1u)"
    );
    assertEqualU32(
        brif0_asX2DselectX2Dcond(&instance),
        3u,
        "as-select-cond()"
    );
    assertEqualU32(
        brif0_asX2DcallX2Dfirst(&instance),
        12u,
        "as-call-first()"
    );
    assertEqualU32(
        brif0_asX2DcallX2Dmid(&instance),
        13u,
        "as-call-mid()"
    );
    assertEqualU32(
        brif0_asX2DcallX2Dlast(&instance),
        14u,
        "as-call-last()"
    );
    assertEqualU32(
        brif0_asX2DcallX5FindirectX2Dfunc(&instance),
        4u,
        "as-call_indirect-func()"
    );
    assertEqualU32(
        brif0_asX2DcallX5FindirectX2Dfirst(&instance),
        4u,
        "as-call_indirect-first()"
    );
    assertEqualU32(
        brif0_asX2DcallX5FindirectX2Dmid(&instance),
        4u,
        "as-call_indirect-mid()"
    );
    assertEqualU32(
        brif0_asX2DcallX5FindirectX2Dlast(&instance),
        4u,
        "as-call_indirect-last()"
    );
    assertEqualU32(
        brif0_asX2DlocalX2EsetX2Dvalue(&instance, 0u),
        4294967295u,
        "as-local.set-value(0u)"
    );
    assertEqualU32(
        brif0_asX2DlocalX2EsetX2Dvalue(&instance, 1u),
        17u,
        "as-local.set-value(1u)"
    );
    assertEqualU32(
        brif0_asX2DlocalX2EteeX2Dvalue(&instance, 0u),
        4294967295u,
        "as-local.tee-value(0u)"
    );
    assertEqualU32(
        brif0_asX2DlocalX2EteeX2Dvalue(&instance, 1u),
        1u,
        "as-local.tee-value(1u)"
    );
    assertEqualU32(
        brif0_asX2DglobalX2EsetX2Dvalue(&instance, 0u),
        4294967295u,
        "as-global.set-value(0u)"
    );
    assertEqualU32(
        brif0_asX2DglobalX2EsetX2Dvalue(&instance, 1u),
        1u,
        "as-global.set-value(1u)"
    );
    assertEqualU32(
        brif0_asX2DloadX2Daddress(&instance),
        1u,
        "as-load-address()"
    );
    assertEqualU32(
        brif0_asX2DloadNX2Daddress(&instance),
        30u,
        "as-loadN-address()"
    );
    assertEqualU32(
        brif0_asX2DstoreX2Daddress(&instance),
        30u,
        "as-store-address()"
    );
    assertEqualU32(
        brif0_asX2DstoreX2Dvalue(&instance),
        31u,
        "as-store-value()"
    );
    assertEqualU32(
        brif0_asX2DstoreNX2Daddress(&instance),
        32u,
        "as-storeN-address()"
    );
    assertEqualU32(
        brif0_asX2DstoreNX2Dvalue(&instance),
        33u,
        "as-storeN-value()"
    );
    assertEqualF64(
        brif0_asX2DunaryX2Doperand(&instance),
        1.0,
        "as-unary-operand()"
    );
    assertEqualU32(
        brif0_asX2DbinaryX2Dleft(&instance),
        1u,
        "as-binary-left()"
    );
    assertEqualU32(
        brif0_asX2DbinaryX2Dright(&instance),
        1u,
        "as-binary-right()"
    );
    assertEqualU32(
        brif0_asX2DtestX2Doperand(&instance),
        0u,
        "as-test-operand()"
    );
    assertEqualU32(
        brif0_asX2DcompareX2Dleft(&instance),
        1u,
        "as-compare-left()"
    );
    assertEqualU32(
        brif0_asX2DcompareX2Dright(&instance),
        1u,
        "as-compare-right()"
    );
    assertEqualU32(
        brif0_asX2DmemoryX2EgrowX2Dsize(&instance),
        1u,
        "as-memory.grow-size()"
    );
    assertEqualU32(
        brif0_nestedX2DblockX2Dvalue(&instance, 0u),
        21u,
        "nested-block-value(0u)"
    );
    assertEqualU32(
        brif0_nestedX2DblockX2Dvalue(&instance, 1u),
        9u,
        "nested-block-value(1u)"
    );
    assertEqualU32(
        brif0_nestedX2DbrX2Dvalue(&instance, 0u),
        5u,
        "nested-br-value(0u)"
    );
    assertEqualU32(
        brif0_nestedX2DbrX2Dvalue(&instance, 1u),
        9u,
        "nested-br-value(1u)"
    );
    assertEqualU32(
        brif0_nestedX2DbrX5FifX2Dvalue(&instance, 0u),
        5u,
        "nested-br_if-value(0u)"
    );
    assertEqualU32(
        brif0_nestedX2DbrX5FifX2Dvalue(&instance, 1u),
        9u,
        "nested-br_if-value(1u)"
    );
    assertEqualU32(
        brif0_nestedX2DbrX5FifX2DvalueX2Dcond(&instance, 0u),
        5u,
        "nested-br_if-value-cond(0u)"
    );
    assertEqualU32(
        brif0_nestedX2DbrX5FifX2DvalueX2Dcond(&instance, 1u),
        9u,
        "nested-br_if-value-cond(1u)"
    );
    assertEqualU32(
        brif0_nestedX2DbrX5FtableX2Dvalue(&instance, 0u),
        5u,
        "nested-br_table-value(0u)"
    );
    assertEqualU32(
        brif0_nestedX2DbrX5FtableX2Dvalue(&instance, 1u),
        9u,
        "nested-br_table-value(1u)"
    );
    assertEqualU32(
        brif0_nestedX2DbrX5FtableX2DvalueX2Dindex(&instance, 0u),
        5u,
        "nested-br_table-value-index(0u)"
    );
    assertEqualU32(
        brif0_nestedX2DbrX5FtableX2DvalueX2Dindex(&instance, 1u),
        9u,
        "nested-br_table-value-index(1u)"
    );
}
