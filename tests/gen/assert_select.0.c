
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_select.0.h"

void test() {
    select0Instance instance;
    select0Instantiate(&instance, resolveTestImports);
    printStart("select.0.wasm");
    assertEqualU32(
        select0_selectX2Di32(&instance, 1u, 2u, 1u),
        1u,
        "select-i32(1u, 2u, 1u)"
    );
    assertEqualU64(
        select0_selectX2Di64(&instance, 2ull, 1ull, 1u),
        2ull,
        "select-i64(2ull, 1ull, 1u)"
    );
    assertEqualF32(
        select0_selectX2Df32(&instance, 1.0, 2.0, 1u),
        1.0,
        "select-f32(1.0, 2.0, 1u)"
    );
    assertEqualF64(
        select0_selectX2Df64(&instance, 1.0, 2.0, 1u),
        1.0,
        "select-f64(1.0, 2.0, 1u)"
    );
    assertEqualU32(
        select0_selectX2Di32(&instance, 1u, 2u, 0u),
        2u,
        "select-i32(1u, 2u, 0u)"
    );
    assertEqualU32(
        select0_selectX2Di32(&instance, 2u, 1u, 0u),
        1u,
        "select-i32(2u, 1u, 0u)"
    );
    assertEqualU64(
        select0_selectX2Di64(&instance, 2ull, 1ull, 4294967295u),
        2ull,
        "select-i64(2ull, 1ull, 4294967295u)"
    );
    assertEqualU64(
        select0_selectX2Di64(&instance, 2ull, 1ull, 4042322160u),
        2ull,
        "select-i64(2ull, 1ull, 4042322160u)"
    );
    assertEqualU32(
        select0_asX2DselectX2Dfirst(&instance, 0u),
        1u,
        "as-select-first(0u)"
    );
    assertEqualU32(
        select0_asX2DselectX2Dfirst(&instance, 1u),
        0u,
        "as-select-first(1u)"
    );
    assertEqualU32(
        select0_asX2DselectX2Dmid(&instance, 0u),
        2u,
        "as-select-mid(0u)"
    );
    assertEqualU32(
        select0_asX2DselectX2Dmid(&instance, 1u),
        2u,
        "as-select-mid(1u)"
    );
    assertEqualU32(
        select0_asX2DselectX2Dlast(&instance, 0u),
        2u,
        "as-select-last(0u)"
    );
    assertEqualU32(
        select0_asX2DselectX2Dlast(&instance, 1u),
        3u,
        "as-select-last(1u)"
    );
    assertEqualU32(
        select0_asX2DloopX2Dfirst(&instance, 0u),
        3u,
        "as-loop-first(0u)"
    );
    assertEqualU32(
        select0_asX2DloopX2Dfirst(&instance, 1u),
        2u,
        "as-loop-first(1u)"
    );
    assertEqualU32(
        select0_asX2DloopX2Dmid(&instance, 0u),
        3u,
        "as-loop-mid(0u)"
    );
    assertEqualU32(
        select0_asX2DloopX2Dmid(&instance, 1u),
        2u,
        "as-loop-mid(1u)"
    );
    assertEqualU32(
        select0_asX2DloopX2Dlast(&instance, 0u),
        3u,
        "as-loop-last(0u)"
    );
    assertEqualU32(
        select0_asX2DloopX2Dlast(&instance, 1u),
        2u,
        "as-loop-last(1u)"
    );
    select0_asX2DifX2Dcondition(&instance, 0u);
    select0_asX2DifX2Dcondition(&instance, 1u);
    assertEqualU32(
        select0_asX2DifX2Dthen(&instance, 0u),
        3u,
        "as-if-then(0u)"
    );
    assertEqualU32(
        select0_asX2DifX2Dthen(&instance, 1u),
        2u,
        "as-if-then(1u)"
    );
    assertEqualU32(
        select0_asX2DifX2Delse(&instance, 0u),
        3u,
        "as-if-else(0u)"
    );
    assertEqualU32(
        select0_asX2DifX2Delse(&instance, 1u),
        2u,
        "as-if-else(1u)"
    );
    assertEqualU32(
        select0_asX2Dbr_ifX2Dfirst(&instance, 0u),
        3u,
        "as-br_if-first(0u)"
    );
    assertEqualU32(
        select0_asX2Dbr_ifX2Dfirst(&instance, 1u),
        2u,
        "as-br_if-first(1u)"
    );
    assertEqualU32(
        select0_asX2Dbr_ifX2Dlast(&instance, 0u),
        2u,
        "as-br_if-last(0u)"
    );
    assertEqualU32(
        select0_asX2Dbr_ifX2Dlast(&instance, 1u),
        2u,
        "as-br_if-last(1u)"
    );
    assertEqualU32(
        select0_asX2Dbr_tableX2Dfirst(&instance, 0u),
        3u,
        "as-br_table-first(0u)"
    );
    assertEqualU32(
        select0_asX2Dbr_tableX2Dfirst(&instance, 1u),
        2u,
        "as-br_table-first(1u)"
    );
    assertEqualU32(
        select0_asX2Dbr_tableX2Dlast(&instance, 0u),
        2u,
        "as-br_table-last(0u)"
    );
    assertEqualU32(
        select0_asX2Dbr_tableX2Dlast(&instance, 1u),
        2u,
        "as-br_table-last(1u)"
    );
    select0_asX2DstoreX2Dfirst(&instance, 0u);
    select0_asX2DstoreX2Dfirst(&instance, 1u);
    select0_asX2DstoreX2Dlast(&instance, 0u);
    select0_asX2DstoreX2Dlast(&instance, 1u);
    assertEqualU32(
        select0_asX2DmemoryX2EgrowX2Dvalue(&instance, 0u),
        1u,
        "as-memory.grow-value(0u)"
    );
    assertEqualU32(
        select0_asX2DmemoryX2EgrowX2Dvalue(&instance, 1u),
        3u,
        "as-memory.grow-value(1u)"
    );
    assertEqualU32(
        select0_asX2DcallX2Dvalue(&instance, 0u),
        2u,
        "as-call-value(0u)"
    );
    assertEqualU32(
        select0_asX2DcallX2Dvalue(&instance, 1u),
        1u,
        "as-call-value(1u)"
    );
    assertEqualU32(
        select0_asX2DreturnX2Dvalue(&instance, 0u),
        2u,
        "as-return-value(0u)"
    );
    assertEqualU32(
        select0_asX2DreturnX2Dvalue(&instance, 1u),
        1u,
        "as-return-value(1u)"
    );
    select0_asX2DdropX2Doperand(&instance, 0u);
    select0_asX2DdropX2Doperand(&instance, 1u);
    assertEqualU32(
        select0_asX2DbrX2Dvalue(&instance, 0u),
        2u,
        "as-br-value(0u)"
    );
    assertEqualU32(
        select0_asX2DbrX2Dvalue(&instance, 1u),
        1u,
        "as-br-value(1u)"
    );
    assertEqualU32(
        select0_asX2DlocalX2EsetX2Dvalue(&instance, 0u),
        2u,
        "as-local.set-value(0u)"
    );
    assertEqualU32(
        select0_asX2DlocalX2EsetX2Dvalue(&instance, 1u),
        1u,
        "as-local.set-value(1u)"
    );
    assertEqualU32(
        select0_asX2DlocalX2EteeX2Dvalue(&instance, 0u),
        2u,
        "as-local.tee-value(0u)"
    );
    assertEqualU32(
        select0_asX2DlocalX2EteeX2Dvalue(&instance, 1u),
        1u,
        "as-local.tee-value(1u)"
    );
    assertEqualU32(
        select0_asX2DglobalX2EsetX2Dvalue(&instance, 0u),
        2u,
        "as-global.set-value(0u)"
    );
    assertEqualU32(
        select0_asX2DglobalX2EsetX2Dvalue(&instance, 1u),
        1u,
        "as-global.set-value(1u)"
    );
    assertEqualU32(
        select0_asX2DloadX2Doperand(&instance, 0u),
        1u,
        "as-load-operand(0u)"
    );
    assertEqualU32(
        select0_asX2DloadX2Doperand(&instance, 1u),
        1u,
        "as-load-operand(1u)"
    );
    assertEqualU32(
        select0_asX2DunaryX2Doperand(&instance, 0u),
        0u,
        "as-unary-operand(0u)"
    );
    assertEqualU32(
        select0_asX2DunaryX2Doperand(&instance, 1u),
        1u,
        "as-unary-operand(1u)"
    );
    assertEqualU32(
        select0_asX2DbinaryX2Doperand(&instance, 0u),
        4u,
        "as-binary-operand(0u)"
    );
    assertEqualU32(
        select0_asX2DbinaryX2Doperand(&instance, 1u),
        1u,
        "as-binary-operand(1u)"
    );
    assertEqualU32(
        select0_asX2DtestX2Doperand(&instance, 0u),
        0u,
        "as-test-operand(0u)"
    );
    assertEqualU32(
        select0_asX2DtestX2Doperand(&instance, 1u),
        1u,
        "as-test-operand(1u)"
    );
    assertEqualU32(
        select0_asX2DcompareX2Dleft(&instance, 0u),
        0u,
        "as-compare-left(0u)"
    );
    assertEqualU32(
        select0_asX2DcompareX2Dleft(&instance, 1u),
        1u,
        "as-compare-left(1u)"
    );
    assertEqualU32(
        select0_asX2DcompareX2Dright(&instance, 0u),
        0u,
        "as-compare-right(0u)"
    );
    assertEqualU32(
        select0_asX2DcompareX2Dright(&instance, 1u),
        1u,
        "as-compare-right(1u)"
    );
    assertEqualU32(
        select0_asX2DconvertX2Doperand(&instance, 0u),
        0u,
        "as-convert-operand(0u)"
    );
    assertEqualU32(
        select0_asX2DconvertX2Doperand(&instance, 1u),
        1u,
        "as-convert-operand(1u)"
    );
}
