
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_br_table.0.h"

void test() {
    brtable0Instance instance;
    brtable0Instantiate(&instance, resolveTestImports);
    printStart("br_table.0.wasm");
    brtable0_typeX2Di32(&instance);
    brtable0_typeX2Di64(&instance);
    brtable0_typeX2Df32(&instance);
    brtable0_typeX2Df64(&instance);
    assertEqualU32(
        brtable0_typeX2Di32X2Dvalue(&instance),
        1u,
        "type-i32-value()"
    );
    assertEqualU64(
        brtable0_typeX2Di64X2Dvalue(&instance),
        2ull,
        "type-i64-value()"
    );
    assertEqualF32(
        brtable0_typeX2Df32X2Dvalue(&instance),
        3.0,
        "type-f32-value()"
    );
    assertEqualF64(
        brtable0_typeX2Df64X2Dvalue(&instance),
        4.0,
        "type-f64-value()"
    );
    assertEqualU32(
        brtable0_empty(&instance, 0u),
        22u,
        "empty(0u)"
    );
    assertEqualU32(
        brtable0_empty(&instance, 1u),
        22u,
        "empty(1u)"
    );
    assertEqualU32(
        brtable0_empty(&instance, 11u),
        22u,
        "empty(11u)"
    );
    assertEqualU32(
        brtable0_empty(&instance, 4294967295u),
        22u,
        "empty(4294967295u)"
    );
    assertEqualU32(
        brtable0_empty(&instance, 4294967196u),
        22u,
        "empty(4294967196u)"
    );
    assertEqualU32(
        brtable0_empty(&instance, 4294967295u),
        22u,
        "empty(4294967295u)"
    );
    assertEqualU32(
        brtable0_emptyX2Dvalue(&instance, 0u),
        33u,
        "empty-value(0u)"
    );
    assertEqualU32(
        brtable0_emptyX2Dvalue(&instance, 1u),
        33u,
        "empty-value(1u)"
    );
    assertEqualU32(
        brtable0_emptyX2Dvalue(&instance, 11u),
        33u,
        "empty-value(11u)"
    );
    assertEqualU32(
        brtable0_emptyX2Dvalue(&instance, 4294967295u),
        33u,
        "empty-value(4294967295u)"
    );
    assertEqualU32(
        brtable0_emptyX2Dvalue(&instance, 4294967196u),
        33u,
        "empty-value(4294967196u)"
    );
    assertEqualU32(
        brtable0_emptyX2Dvalue(&instance, 4294967295u),
        33u,
        "empty-value(4294967295u)"
    );
    assertEqualU32(
        brtable0_singleton(&instance, 0u),
        22u,
        "singleton(0u)"
    );
    assertEqualU32(
        brtable0_singleton(&instance, 1u),
        20u,
        "singleton(1u)"
    );
    assertEqualU32(
        brtable0_singleton(&instance, 11u),
        20u,
        "singleton(11u)"
    );
    assertEqualU32(
        brtable0_singleton(&instance, 4294967295u),
        20u,
        "singleton(4294967295u)"
    );
    assertEqualU32(
        brtable0_singleton(&instance, 4294967196u),
        20u,
        "singleton(4294967196u)"
    );
    assertEqualU32(
        brtable0_singleton(&instance, 4294967295u),
        20u,
        "singleton(4294967295u)"
    );
    assertEqualU32(
        brtable0_singletonX2Dvalue(&instance, 0u),
        32u,
        "singleton-value(0u)"
    );
    assertEqualU32(
        brtable0_singletonX2Dvalue(&instance, 1u),
        33u,
        "singleton-value(1u)"
    );
    assertEqualU32(
        brtable0_singletonX2Dvalue(&instance, 11u),
        33u,
        "singleton-value(11u)"
    );
    assertEqualU32(
        brtable0_singletonX2Dvalue(&instance, 4294967295u),
        33u,
        "singleton-value(4294967295u)"
    );
    assertEqualU32(
        brtable0_singletonX2Dvalue(&instance, 4294967196u),
        33u,
        "singleton-value(4294967196u)"
    );
    assertEqualU32(
        brtable0_singletonX2Dvalue(&instance, 4294967295u),
        33u,
        "singleton-value(4294967295u)"
    );
    assertEqualU32(
        brtable0_multiple(&instance, 0u),
        103u,
        "multiple(0u)"
    );
    assertEqualU32(
        brtable0_multiple(&instance, 1u),
        102u,
        "multiple(1u)"
    );
    assertEqualU32(
        brtable0_multiple(&instance, 2u),
        101u,
        "multiple(2u)"
    );
    assertEqualU32(
        brtable0_multiple(&instance, 3u),
        100u,
        "multiple(3u)"
    );
    assertEqualU32(
        brtable0_multiple(&instance, 4u),
        104u,
        "multiple(4u)"
    );
    assertEqualU32(
        brtable0_multiple(&instance, 5u),
        104u,
        "multiple(5u)"
    );
    assertEqualU32(
        brtable0_multiple(&instance, 6u),
        104u,
        "multiple(6u)"
    );
    assertEqualU32(
        brtable0_multiple(&instance, 10u),
        104u,
        "multiple(10u)"
    );
    assertEqualU32(
        brtable0_multiple(&instance, 4294967295u),
        104u,
        "multiple(4294967295u)"
    );
    assertEqualU32(
        brtable0_multiple(&instance, 4294967295u),
        104u,
        "multiple(4294967295u)"
    );
    assertEqualU32(
        brtable0_multipleX2Dvalue(&instance, 0u),
        213u,
        "multiple-value(0u)"
    );
    assertEqualU32(
        brtable0_multipleX2Dvalue(&instance, 1u),
        212u,
        "multiple-value(1u)"
    );
    assertEqualU32(
        brtable0_multipleX2Dvalue(&instance, 2u),
        211u,
        "multiple-value(2u)"
    );
    assertEqualU32(
        brtable0_multipleX2Dvalue(&instance, 3u),
        210u,
        "multiple-value(3u)"
    );
    assertEqualU32(
        brtable0_multipleX2Dvalue(&instance, 4u),
        214u,
        "multiple-value(4u)"
    );
    assertEqualU32(
        brtable0_multipleX2Dvalue(&instance, 5u),
        214u,
        "multiple-value(5u)"
    );
    assertEqualU32(
        brtable0_multipleX2Dvalue(&instance, 6u),
        214u,
        "multiple-value(6u)"
    );
    assertEqualU32(
        brtable0_multipleX2Dvalue(&instance, 10u),
        214u,
        "multiple-value(10u)"
    );
    assertEqualU32(
        brtable0_multipleX2Dvalue(&instance, 4294967295u),
        214u,
        "multiple-value(4294967295u)"
    );
    assertEqualU32(
        brtable0_multipleX2Dvalue(&instance, 4294967295u),
        214u,
        "multiple-value(4294967295u)"
    );
    assertEqualU32(
        brtable0_large(&instance, 0u),
        0u,
        "large(0u)"
    );
    assertEqualU32(
        brtable0_large(&instance, 1u),
        1u,
        "large(1u)"
    );
    assertEqualU32(
        brtable0_large(&instance, 100u),
        0u,
        "large(100u)"
    );
    assertEqualU32(
        brtable0_large(&instance, 101u),
        1u,
        "large(101u)"
    );
    assertEqualU32(
        brtable0_large(&instance, 10000u),
        0u,
        "large(10000u)"
    );
    assertEqualU32(
        brtable0_large(&instance, 10001u),
        1u,
        "large(10001u)"
    );
    assertEqualU32(
        brtable0_large(&instance, 1000000u),
        1u,
        "large(1000000u)"
    );
    assertEqualU32(
        brtable0_large(&instance, 1000001u),
        1u,
        "large(1000001u)"
    );
    brtable0_asX2DblockX2Dfirst(&instance);
    brtable0_asX2DblockX2Dmid(&instance);
    brtable0_asX2DblockX2Dlast(&instance);
    assertEqualU32(
        brtable0_asX2DblockX2Dvalue(&instance),
        2u,
        "as-block-value()"
    );
    assertEqualU32(
        brtable0_asX2DloopX2Dfirst(&instance),
        3u,
        "as-loop-first()"
    );
    assertEqualU32(
        brtable0_asX2DloopX2Dmid(&instance),
        4u,
        "as-loop-mid()"
    );
    assertEqualU32(
        brtable0_asX2DloopX2Dlast(&instance),
        5u,
        "as-loop-last()"
    );
    assertEqualU32(
        brtable0_asX2DbrX2Dvalue(&instance),
        9u,
        "as-br-value()"
    );
    brtable0_asX2DbrX5FifX2Dcond(&instance);
    assertEqualU32(
        brtable0_asX2DbrX5FifX2Dvalue(&instance),
        8u,
        "as-br_if-value()"
    );
    assertEqualU32(
        brtable0_asX2DbrX5FifX2DvalueX2Dcond(&instance),
        9u,
        "as-br_if-value-cond()"
    );
    brtable0_asX2DbrX5FtableX2Dindex(&instance);
    assertEqualU32(
        brtable0_asX2DbrX5FtableX2Dvalue(&instance),
        10u,
        "as-br_table-value()"
    );
    assertEqualU32(
        brtable0_asX2DbrX5FtableX2DvalueX2Dindex(&instance),
        11u,
        "as-br_table-value-index()"
    );
    assertEqualU64(
        brtable0_asX2DreturnX2Dvalue(&instance),
        7ull,
        "as-return-value()"
    );
    assertEqualU32(
        brtable0_asX2DifX2Dcond(&instance),
        2u,
        "as-if-cond()"
    );
    assertEqualU32(
        brtable0_asX2DifX2Dthen(&instance, 1u, 6u),
        3u,
        "as-if-then(1u, 6u)"
    );
    assertEqualU32(
        brtable0_asX2DifX2Dthen(&instance, 0u, 6u),
        6u,
        "as-if-then(0u, 6u)"
    );
    assertEqualU32(
        brtable0_asX2DifX2Delse(&instance, 0u, 6u),
        4u,
        "as-if-else(0u, 6u)"
    );
    assertEqualU32(
        brtable0_asX2DifX2Delse(&instance, 1u, 6u),
        6u,
        "as-if-else(1u, 6u)"
    );
    assertEqualU32(
        brtable0_asX2DselectX2Dfirst(&instance, 0u, 6u),
        5u,
        "as-select-first(0u, 6u)"
    );
    assertEqualU32(
        brtable0_asX2DselectX2Dfirst(&instance, 1u, 6u),
        5u,
        "as-select-first(1u, 6u)"
    );
    assertEqualU32(
        brtable0_asX2DselectX2Dsecond(&instance, 0u, 6u),
        6u,
        "as-select-second(0u, 6u)"
    );
    assertEqualU32(
        brtable0_asX2DselectX2Dsecond(&instance, 1u, 6u),
        6u,
        "as-select-second(1u, 6u)"
    );
    assertEqualU32(
        brtable0_asX2DselectX2Dcond(&instance),
        7u,
        "as-select-cond()"
    );
    assertEqualU32(
        brtable0_asX2DcallX2Dfirst(&instance),
        12u,
        "as-call-first()"
    );
    assertEqualU32(
        brtable0_asX2DcallX2Dmid(&instance),
        13u,
        "as-call-mid()"
    );
    assertEqualU32(
        brtable0_asX2DcallX2Dlast(&instance),
        14u,
        "as-call-last()"
    );
    assertEqualU32(
        brtable0_asX2DcallX5FindirectX2Dfirst(&instance),
        20u,
        "as-call_indirect-first()"
    );
    assertEqualU32(
        brtable0_asX2DcallX5FindirectX2Dmid(&instance),
        21u,
        "as-call_indirect-mid()"
    );
    assertEqualU32(
        brtable0_asX2DcallX5FindirectX2Dlast(&instance),
        22u,
        "as-call_indirect-last()"
    );
    assertEqualU32(
        brtable0_asX2DcallX5FindirectX2Dfunc(&instance),
        23u,
        "as-call_indirect-func()"
    );
    assertEqualU32(
        brtable0_asX2DlocalX2EsetX2Dvalue(&instance),
        17u,
        "as-local.set-value()"
    );
    assertEqualU32(
        brtable0_asX2DlocalX2EteeX2Dvalue(&instance),
        1u,
        "as-local.tee-value()"
    );
    assertEqualU32(
        brtable0_asX2DglobalX2EsetX2Dvalue(&instance),
        1u,
        "as-global.set-value()"
    );
    assertEqualF32(
        brtable0_asX2DloadX2Daddress(&instance),
        1.7000000476837158,
        "as-load-address()"
    );
    assertEqualU64(
        brtable0_asX2DloadNX2Daddress(&instance),
        30ull,
        "as-loadN-address()"
    );
    assertEqualU32(
        brtable0_asX2DstoreX2Daddress(&instance),
        30u,
        "as-store-address()"
    );
    assertEqualU32(
        brtable0_asX2DstoreX2Dvalue(&instance),
        31u,
        "as-store-value()"
    );
    assertEqualU32(
        brtable0_asX2DstoreNX2Daddress(&instance),
        32u,
        "as-storeN-address()"
    );
    assertEqualU32(
        brtable0_asX2DstoreNX2Dvalue(&instance),
        33u,
        "as-storeN-value()"
    );
    assertEqualF32(
        brtable0_asX2DunaryX2Doperand(&instance),
        3.4000000953674316,
        "as-unary-operand()"
    );
    assertEqualU32(
        brtable0_asX2DbinaryX2Dleft(&instance),
        3u,
        "as-binary-left()"
    );
    assertEqualU64(
        brtable0_asX2DbinaryX2Dright(&instance),
        45ull,
        "as-binary-right()"
    );
    assertEqualU32(
        brtable0_asX2DtestX2Doperand(&instance),
        44u,
        "as-test-operand()"
    );
    assertEqualU32(
        brtable0_asX2DcompareX2Dleft(&instance),
        43u,
        "as-compare-left()"
    );
    assertEqualU32(
        brtable0_asX2DcompareX2Dright(&instance),
        42u,
        "as-compare-right()"
    );
    assertEqualU32(
        brtable0_asX2DconvertX2Doperand(&instance),
        41u,
        "as-convert-operand()"
    );
    assertEqualU32(
        brtable0_asX2DmemoryX2EgrowX2Dsize(&instance),
        40u,
        "as-memory.grow-size()"
    );
    assertEqualU32(
        brtable0_nestedX2DblockX2Dvalue(&instance, 0u),
        19u,
        "nested-block-value(0u)"
    );
    assertEqualU32(
        brtable0_nestedX2DblockX2Dvalue(&instance, 1u),
        17u,
        "nested-block-value(1u)"
    );
    assertEqualU32(
        brtable0_nestedX2DblockX2Dvalue(&instance, 2u),
        16u,
        "nested-block-value(2u)"
    );
    assertEqualU32(
        brtable0_nestedX2DblockX2Dvalue(&instance, 10u),
        16u,
        "nested-block-value(10u)"
    );
    assertEqualU32(
        brtable0_nestedX2DblockX2Dvalue(&instance, 4294967295u),
        16u,
        "nested-block-value(4294967295u)"
    );
    assertEqualU32(
        brtable0_nestedX2DblockX2Dvalue(&instance, 100000u),
        16u,
        "nested-block-value(100000u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX2Dvalue(&instance, 0u),
        8u,
        "nested-br-value(0u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX2Dvalue(&instance, 1u),
        9u,
        "nested-br-value(1u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX2Dvalue(&instance, 2u),
        17u,
        "nested-br-value(2u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX2Dvalue(&instance, 11u),
        17u,
        "nested-br-value(11u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX2Dvalue(&instance, 4294967292u),
        17u,
        "nested-br-value(4294967292u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX2Dvalue(&instance, 10213210u),
        17u,
        "nested-br-value(10213210u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2Dvalue(&instance, 0u),
        17u,
        "nested-br_if-value(0u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2Dvalue(&instance, 1u),
        9u,
        "nested-br_if-value(1u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2Dvalue(&instance, 2u),
        8u,
        "nested-br_if-value(2u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2Dvalue(&instance, 9u),
        8u,
        "nested-br_if-value(9u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2Dvalue(&instance, 4294967287u),
        8u,
        "nested-br_if-value(4294967287u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2Dvalue(&instance, 999999u),
        8u,
        "nested-br_if-value(999999u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2DvalueX2Dcond(&instance, 0u),
        9u,
        "nested-br_if-value-cond(0u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2DvalueX2Dcond(&instance, 1u),
        8u,
        "nested-br_if-value-cond(1u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2DvalueX2Dcond(&instance, 2u),
        9u,
        "nested-br_if-value-cond(2u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2DvalueX2Dcond(&instance, 3u),
        9u,
        "nested-br_if-value-cond(3u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2DvalueX2Dcond(&instance, 4293967296u),
        9u,
        "nested-br_if-value-cond(4293967296u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FifX2DvalueX2Dcond(&instance, 9423975u),
        9u,
        "nested-br_if-value-cond(9423975u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2Dvalue(&instance, 0u),
        17u,
        "nested-br_table-value(0u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2Dvalue(&instance, 1u),
        9u,
        "nested-br_table-value(1u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2Dvalue(&instance, 2u),
        8u,
        "nested-br_table-value(2u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2Dvalue(&instance, 9u),
        8u,
        "nested-br_table-value(9u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2Dvalue(&instance, 4294967287u),
        8u,
        "nested-br_table-value(4294967287u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2Dvalue(&instance, 999999u),
        8u,
        "nested-br_table-value(999999u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2DvalueX2Dindex(&instance, 0u),
        9u,
        "nested-br_table-value-index(0u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2DvalueX2Dindex(&instance, 1u),
        8u,
        "nested-br_table-value-index(1u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2DvalueX2Dindex(&instance, 2u),
        9u,
        "nested-br_table-value-index(2u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2DvalueX2Dindex(&instance, 3u),
        9u,
        "nested-br_table-value-index(3u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2DvalueX2Dindex(&instance, 4293967296u),
        9u,
        "nested-br_table-value-index(4293967296u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2DvalueX2Dindex(&instance, 9423975u),
        9u,
        "nested-br_table-value-index(9423975u)"
    );
    assertEqualU32(
        brtable0_nestedX2DbrX5FtableX2DloopX2Dblock(&instance, 1u),
        3u,
        "nested-br_table-loop-block(1u)"
    );
}
