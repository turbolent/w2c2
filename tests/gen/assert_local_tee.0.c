
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_local_tee.0.h"

void test() {
    localtee0Instance instance;
    localtee0Instantiate(&instance, resolveTestImports);
    printStart("local_tee.0.wasm");
    assertEqualU32(
        localtee0_typeX2DlocalX2Di32(&instance),
        0u,
        "type-local-i32()"
    );
    assertEqualU64(
        localtee0_typeX2DlocalX2Di64(&instance),
        0ull,
        "type-local-i64()"
    );
    assertEqualF32(
        localtee0_typeX2DlocalX2Df32(&instance),
        0.0,
        "type-local-f32()"
    );
    assertEqualF64(
        localtee0_typeX2DlocalX2Df64(&instance),
        0.0,
        "type-local-f64()"
    );
    assertEqualU32(
        localtee0_typeX2DparamX2Di32(&instance, 2u),
        10u,
        "type-param-i32(2u)"
    );
    assertEqualU64(
        localtee0_typeX2DparamX2Di64(&instance, 3ull),
        11ull,
        "type-param-i64(3ull)"
    );
    assertEqualF32(
        localtee0_typeX2DparamX2Df32(&instance, 4.400000095367432),
        11.100000381469727,
        "type-param-f32(4.400000095367432)"
    );
    assertEqualF64(
        localtee0_typeX2DparamX2Df64(&instance, 5.5),
        12.2,
        "type-param-f64(5.5)"
    );
    assertEqualU32(
        localtee0_asX2DblockX2Dfirst(&instance, 0u),
        1u,
        "as-block-first(0u)"
    );
    assertEqualU32(
        localtee0_asX2DblockX2Dmid(&instance, 0u),
        1u,
        "as-block-mid(0u)"
    );
    assertEqualU32(
        localtee0_asX2DblockX2Dlast(&instance, 0u),
        1u,
        "as-block-last(0u)"
    );
    assertEqualU32(
        localtee0_asX2DloopX2Dfirst(&instance, 0u),
        3u,
        "as-loop-first(0u)"
    );
    assertEqualU32(
        localtee0_asX2DloopX2Dmid(&instance, 0u),
        4u,
        "as-loop-mid(0u)"
    );
    assertEqualU32(
        localtee0_asX2DloopX2Dlast(&instance, 0u),
        5u,
        "as-loop-last(0u)"
    );
    assertEqualU32(
        localtee0_asX2DbrX2Dvalue(&instance, 0u),
        9u,
        "as-br-value(0u)"
    );
    localtee0_asX2Dbr_ifX2Dcond(&instance, 0u);
    assertEqualU32(
        localtee0_asX2Dbr_ifX2Dvalue(&instance, 0u),
        8u,
        "as-br_if-value(0u)"
    );
    assertEqualU32(
        localtee0_asX2Dbr_ifX2DvalueX2Dcond(&instance, 0u),
        6u,
        "as-br_if-value-cond(0u)"
    );
    localtee0_asX2Dbr_tableX2Dindex(&instance, 0u);
    assertEqualU32(
        localtee0_asX2Dbr_tableX2Dvalue(&instance, 0u),
        10u,
        "as-br_table-value(0u)"
    );
    assertEqualU32(
        localtee0_asX2Dbr_tableX2DvalueX2Dindex(&instance, 0u),
        6u,
        "as-br_table-value-index(0u)"
    );
    assertEqualU32(
        localtee0_asX2DreturnX2Dvalue(&instance, 0u),
        7u,
        "as-return-value(0u)"
    );
    assertEqualU32(
        localtee0_asX2DifX2Dcond(&instance, 0u),
        0u,
        "as-if-cond(0u)"
    );
    assertEqualU32(
        localtee0_asX2DifX2Dthen(&instance, 1u),
        3u,
        "as-if-then(1u)"
    );
    assertEqualU32(
        localtee0_asX2DifX2Delse(&instance, 0u),
        4u,
        "as-if-else(0u)"
    );
    assertEqualU32(
        localtee0_asX2DselectX2Dfirst(&instance, 0u, 1u),
        5u,
        "as-select-first(0u, 1u)"
    );
    assertEqualU32(
        localtee0_asX2DselectX2Dsecond(&instance, 0u, 0u),
        6u,
        "as-select-second(0u, 0u)"
    );
    assertEqualU32(
        localtee0_asX2DselectX2Dcond(&instance, 0u),
        0u,
        "as-select-cond(0u)"
    );
    assertEqualU32(
        localtee0_asX2DcallX2Dfirst(&instance, 0u),
        4294967295u,
        "as-call-first(0u)"
    );
    assertEqualU32(
        localtee0_asX2DcallX2Dmid(&instance, 0u),
        4294967295u,
        "as-call-mid(0u)"
    );
    assertEqualU32(
        localtee0_asX2DcallX2Dlast(&instance, 0u),
        4294967295u,
        "as-call-last(0u)"
    );
    assertEqualU32(
        localtee0_asX2Dcall_indirectX2Dfirst(&instance, 0u),
        4294967295u,
        "as-call_indirect-first(0u)"
    );
    assertEqualU32(
        localtee0_asX2Dcall_indirectX2Dmid(&instance, 0u),
        4294967295u,
        "as-call_indirect-mid(0u)"
    );
    assertEqualU32(
        localtee0_asX2Dcall_indirectX2Dlast(&instance, 0u),
        4294967295u,
        "as-call_indirect-last(0u)"
    );
    assertEqualU32(
        localtee0_asX2Dcall_indirectX2Dindex(&instance, 0u),
        4294967295u,
        "as-call_indirect-index(0u)"
    );
    localtee0_asX2DlocalX2EsetX2Dvalue(&instance);
    assertEqualU32(
        localtee0_asX2DlocalX2EteeX2Dvalue(&instance, 0u),
        1u,
        "as-local.tee-value(0u)"
    );
    localtee0_asX2DglobalX2EsetX2Dvalue(&instance);
    assertEqualU32(
        localtee0_asX2DloadX2Daddress(&instance, 0u),
        0u,
        "as-load-address(0u)"
    );
    assertEqualU32(
        localtee0_asX2DloadNX2Daddress(&instance, 0u),
        0u,
        "as-loadN-address(0u)"
    );
    localtee0_asX2DstoreX2Daddress(&instance, 0u);
    localtee0_asX2DstoreX2Dvalue(&instance, 0u);
    localtee0_asX2DstoreNX2Daddress(&instance, 0u);
    localtee0_asX2DstoreNX2Dvalue(&instance, 0u);
    assertEqualU32(
        localtee0_asX2DbinaryX2Dleft(&instance, 0u),
        13u,
        "as-binary-left(0u)"
    );
    assertEqualU32(
        localtee0_asX2DbinaryX2Dright(&instance, 0u),
        6u,
        "as-binary-right(0u)"
    );
    assertEqualU32(
        localtee0_asX2DtestX2Doperand(&instance, 0u),
        1u,
        "as-test-operand(0u)"
    );
    assertEqualU32(
        localtee0_asX2DcompareX2Dleft(&instance, 0u),
        0u,
        "as-compare-left(0u)"
    );
    assertEqualU32(
        localtee0_asX2DcompareX2Dright(&instance, 0u),
        1u,
        "as-compare-right(0u)"
    );
    assertEqualU32(
        localtee0_asX2DconvertX2Doperand(&instance, 0ull),
        41u,
        "as-convert-operand(0ull)"
    );
    assertEqualU32(
        localtee0_asX2DmemoryX2EgrowX2Dsize(&instance, 0u),
        1u,
        "as-memory.grow-size(0u)"
    );
    localtee0_typeX2Dmixed(&instance, 1ull, 2.200000047683716, 3.3, 4u, 5u);
    assertEqualU64(
        localtee0_write(&instance, 1ull, 2.0, 3.3, 4u, 5u),
        56ull,
        "write(1ull, 2.0, 3.3, 4u, 5u)"
    );
    assertEqualF64(
        localtee0_result(&instance, 18446744073709551615ull, -2.0, -3.3, 4294967292u, 4294967291u),
        34.8,
        "result(18446744073709551615ull, -2.0, -3.3, 4294967292u, 4294967291u)"
    );
}
