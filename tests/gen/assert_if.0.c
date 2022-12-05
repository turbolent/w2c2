
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_if.0.h"

void test() {
    if0Instance instance;
    if0Instantiate(&instance, resolveTestImports);
    printStart("if.0.wasm");
    if0_empty(&instance, 0u);
    if0_empty(&instance, 1u);
    if0_empty(&instance, 100u);
    if0_empty(&instance, 4294967294u);
    assertEqualU32(
        if0_singular(&instance, 0u),
        8u,
        "singular(0u)"
    );
    assertEqualU32(
        if0_singular(&instance, 1u),
        7u,
        "singular(1u)"
    );
    assertEqualU32(
        if0_singular(&instance, 10u),
        7u,
        "singular(10u)"
    );
    assertEqualU32(
        if0_singular(&instance, 4294967286u),
        7u,
        "singular(4294967286u)"
    );
    assertEqualU32(
        if0_multi(&instance, 0u),
        9u,
        "multi(0u)"
    );
    assertEqualU32(
        if0_multi(&instance, 1u),
        8u,
        "multi(1u)"
    );
    assertEqualU32(
        if0_multi(&instance, 13u),
        8u,
        "multi(13u)"
    );
    assertEqualU32(
        if0_multi(&instance, 4294967291u),
        8u,
        "multi(4294967291u)"
    );
    assertEqualU32(
        if0_nested(&instance, 0u, 0u),
        11u,
        "nested(0u, 0u)"
    );
    assertEqualU32(
        if0_nested(&instance, 1u, 0u),
        10u,
        "nested(1u, 0u)"
    );
    assertEqualU32(
        if0_nested(&instance, 0u, 1u),
        10u,
        "nested(0u, 1u)"
    );
    assertEqualU32(
        if0_nested(&instance, 3u, 2u),
        9u,
        "nested(3u, 2u)"
    );
    assertEqualU32(
        if0_nested(&instance, 0u, 4294967196u),
        10u,
        "nested(0u, 4294967196u)"
    );
    assertEqualU32(
        if0_nested(&instance, 10u, 10u),
        9u,
        "nested(10u, 10u)"
    );
    assertEqualU32(
        if0_nested(&instance, 0u, 4294967295u),
        10u,
        "nested(0u, 4294967295u)"
    );
    assertEqualU32(
        if0_nested(&instance, 4294967185u, 4294967294u),
        9u,
        "nested(4294967185u, 4294967294u)"
    );
    assertEqualU32(
        if0_asX2DselectX2Dfirst(&instance, 0u),
        0u,
        "as-select-first(0u)"
    );
    assertEqualU32(
        if0_asX2DselectX2Dfirst(&instance, 1u),
        1u,
        "as-select-first(1u)"
    );
    assertEqualU32(
        if0_asX2DselectX2Dmid(&instance, 0u),
        2u,
        "as-select-mid(0u)"
    );
    assertEqualU32(
        if0_asX2DselectX2Dmid(&instance, 1u),
        2u,
        "as-select-mid(1u)"
    );
    assertEqualU32(
        if0_asX2DselectX2Dlast(&instance, 0u),
        3u,
        "as-select-last(0u)"
    );
    assertEqualU32(
        if0_asX2DselectX2Dlast(&instance, 1u),
        2u,
        "as-select-last(1u)"
    );
    assertEqualU32(
        if0_asX2DloopX2Dfirst(&instance, 0u),
        0u,
        "as-loop-first(0u)"
    );
    assertEqualU32(
        if0_asX2DloopX2Dfirst(&instance, 1u),
        1u,
        "as-loop-first(1u)"
    );
    assertEqualU32(
        if0_asX2DloopX2Dmid(&instance, 0u),
        0u,
        "as-loop-mid(0u)"
    );
    assertEqualU32(
        if0_asX2DloopX2Dmid(&instance, 1u),
        1u,
        "as-loop-mid(1u)"
    );
    assertEqualU32(
        if0_asX2DloopX2Dlast(&instance, 0u),
        0u,
        "as-loop-last(0u)"
    );
    assertEqualU32(
        if0_asX2DloopX2Dlast(&instance, 1u),
        1u,
        "as-loop-last(1u)"
    );
    assertEqualU32(
        if0_asX2DifX2Dcondition(&instance, 0u),
        3u,
        "as-if-condition(0u)"
    );
    assertEqualU32(
        if0_asX2DifX2Dcondition(&instance, 1u),
        2u,
        "as-if-condition(1u)"
    );
    assertEqualU32(
        if0_asX2DbrX5FifX2Dfirst(&instance, 0u),
        0u,
        "as-br_if-first(0u)"
    );
    assertEqualU32(
        if0_asX2DbrX5FifX2Dfirst(&instance, 1u),
        1u,
        "as-br_if-first(1u)"
    );
    assertEqualU32(
        if0_asX2DbrX5FifX2Dlast(&instance, 0u),
        3u,
        "as-br_if-last(0u)"
    );
    assertEqualU32(
        if0_asX2DbrX5FifX2Dlast(&instance, 1u),
        2u,
        "as-br_if-last(1u)"
    );
    assertEqualU32(
        if0_asX2DbrX5FtableX2Dfirst(&instance, 0u),
        0u,
        "as-br_table-first(0u)"
    );
    assertEqualU32(
        if0_asX2DbrX5FtableX2Dfirst(&instance, 1u),
        1u,
        "as-br_table-first(1u)"
    );
    assertEqualU32(
        if0_asX2DbrX5FtableX2Dlast(&instance, 0u),
        2u,
        "as-br_table-last(0u)"
    );
    assertEqualU32(
        if0_asX2DbrX5FtableX2Dlast(&instance, 1u),
        2u,
        "as-br_table-last(1u)"
    );
    assertEqualU32(
        if0_asX2DcallX5FindirectX2Dfirst(&instance, 0u),
        0u,
        "as-call_indirect-first(0u)"
    );
    assertEqualU32(
        if0_asX2DcallX5FindirectX2Dfirst(&instance, 1u),
        1u,
        "as-call_indirect-first(1u)"
    );
    assertEqualU32(
        if0_asX2DcallX5FindirectX2Dmid(&instance, 0u),
        2u,
        "as-call_indirect-mid(0u)"
    );
    assertEqualU32(
        if0_asX2DcallX5FindirectX2Dmid(&instance, 1u),
        2u,
        "as-call_indirect-mid(1u)"
    );
    assertEqualU32(
        if0_asX2DcallX5FindirectX2Dlast(&instance, 0u),
        2u,
        "as-call_indirect-last(0u)"
    );
    if0_asX2DstoreX2Dfirst(&instance, 0u);
    if0_asX2DstoreX2Dfirst(&instance, 1u);
    if0_asX2DstoreX2Dlast(&instance, 0u);
    if0_asX2DstoreX2Dlast(&instance, 1u);
    assertEqualU32(
        if0_asX2DmemoryX2EgrowX2Dvalue(&instance, 0u),
        1u,
        "as-memory.grow-value(0u)"
    );
    assertEqualU32(
        if0_asX2DmemoryX2EgrowX2Dvalue(&instance, 1u),
        1u,
        "as-memory.grow-value(1u)"
    );
    assertEqualU32(
        if0_asX2DcallX2Dvalue(&instance, 0u),
        0u,
        "as-call-value(0u)"
    );
    assertEqualU32(
        if0_asX2DcallX2Dvalue(&instance, 1u),
        1u,
        "as-call-value(1u)"
    );
    assertEqualU32(
        if0_asX2DreturnX2Dvalue(&instance, 0u),
        0u,
        "as-return-value(0u)"
    );
    assertEqualU32(
        if0_asX2DreturnX2Dvalue(&instance, 1u),
        1u,
        "as-return-value(1u)"
    );
    if0_asX2DdropX2Doperand(&instance, 0u);
    if0_asX2DdropX2Doperand(&instance, 1u);
    assertEqualU32(
        if0_asX2DbrX2Dvalue(&instance, 0u),
        0u,
        "as-br-value(0u)"
    );
    assertEqualU32(
        if0_asX2DbrX2Dvalue(&instance, 1u),
        1u,
        "as-br-value(1u)"
    );
    assertEqualU32(
        if0_asX2DlocalX2EsetX2Dvalue(&instance, 0u),
        0u,
        "as-local.set-value(0u)"
    );
    assertEqualU32(
        if0_asX2DlocalX2EsetX2Dvalue(&instance, 1u),
        1u,
        "as-local.set-value(1u)"
    );
    assertEqualU32(
        if0_asX2DlocalX2EteeX2Dvalue(&instance, 0u),
        0u,
        "as-local.tee-value(0u)"
    );
    assertEqualU32(
        if0_asX2DlocalX2EteeX2Dvalue(&instance, 1u),
        1u,
        "as-local.tee-value(1u)"
    );
    assertEqualU32(
        if0_asX2DglobalX2EsetX2Dvalue(&instance, 0u),
        0u,
        "as-global.set-value(0u)"
    );
    assertEqualU32(
        if0_asX2DglobalX2EsetX2Dvalue(&instance, 1u),
        1u,
        "as-global.set-value(1u)"
    );
    assertEqualU32(
        if0_asX2DloadX2Doperand(&instance, 0u),
        0u,
        "as-load-operand(0u)"
    );
    assertEqualU32(
        if0_asX2DloadX2Doperand(&instance, 1u),
        0u,
        "as-load-operand(1u)"
    );
    assertEqualU32(
        if0_asX2DunaryX2Doperand(&instance, 0u),
        0u,
        "as-unary-operand(0u)"
    );
    assertEqualU32(
        if0_asX2DunaryX2Doperand(&instance, 1u),
        0u,
        "as-unary-operand(1u)"
    );
    assertEqualU32(
        if0_asX2DunaryX2Doperand(&instance, 4294967295u),
        0u,
        "as-unary-operand(4294967295u)"
    );
    assertEqualU32(
        if0_asX2DbinaryX2Doperand(&instance, 0u, 0u),
        15u,
        "as-binary-operand(0u, 0u)"
    );
    assertEqualU32(
        if0_asX2DbinaryX2Doperand(&instance, 0u, 1u),
        4294967284u,
        "as-binary-operand(0u, 1u)"
    );
    assertEqualU32(
        if0_asX2DbinaryX2Doperand(&instance, 1u, 0u),
        4294967281u,
        "as-binary-operand(1u, 0u)"
    );
    assertEqualU32(
        if0_asX2DbinaryX2Doperand(&instance, 1u, 1u),
        12u,
        "as-binary-operand(1u, 1u)"
    );
    assertEqualU32(
        if0_asX2DtestX2Doperand(&instance, 0u),
        1u,
        "as-test-operand(0u)"
    );
    assertEqualU32(
        if0_asX2DtestX2Doperand(&instance, 1u),
        0u,
        "as-test-operand(1u)"
    );
    assertEqualU32(
        if0_asX2DcompareX2Doperand(&instance, 0u, 0u),
        1u,
        "as-compare-operand(0u, 0u)"
    );
    assertEqualU32(
        if0_asX2DcompareX2Doperand(&instance, 0u, 1u),
        0u,
        "as-compare-operand(0u, 1u)"
    );
    assertEqualU32(
        if0_asX2DcompareX2Doperand(&instance, 1u, 0u),
        1u,
        "as-compare-operand(1u, 0u)"
    );
    assertEqualU32(
        if0_asX2DcompareX2Doperand(&instance, 1u, 1u),
        0u,
        "as-compare-operand(1u, 1u)"
    );
    assertEqualU32(
        if0_breakX2Dbare(&instance),
        19u,
        "break-bare()"
    );
    assertEqualU32(
        if0_breakX2Dvalue(&instance, 1u),
        18u,
        "break-value(1u)"
    );
    assertEqualU32(
        if0_breakX2Dvalue(&instance, 0u),
        21u,
        "break-value(0u)"
    );
    assertEqualU32(
        if0_effects(&instance, 1u),
        4294967282u,
        "effects(1u)"
    );
    assertEqualU32(
        if0_effects(&instance, 0u),
        4294967290u,
        "effects(0u)"
    );
}
