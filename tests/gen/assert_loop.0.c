
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_loop.0.h"

void test() {
    loop0Instance instance;
    loop0Instantiate(&instance, resolveTestImports);
    printStart("loop.0.wasm");
    loop0_empty(&instance);
    assertEqualU32(
        loop0_singular(&instance),
        7u,
        "singular()"
    );
    assertEqualU32(
        loop0_nested(&instance),
        9u,
        "nested()"
    );
    assertEqualU32(
        loop0_deep(&instance),
        150u,
        "deep()"
    );
    assertEqualU32(
        loop0_asX2DselectX2Dfirst(&instance),
        1u,
        "as-select-first()"
    );
    assertEqualU32(
        loop0_asX2DselectX2Dmid(&instance),
        2u,
        "as-select-mid()"
    );
    assertEqualU32(
        loop0_asX2DselectX2Dlast(&instance),
        2u,
        "as-select-last()"
    );
    loop0_asX2DifX2Dcondition(&instance);
    assertEqualU32(
        loop0_asX2DifX2Dthen(&instance),
        1u,
        "as-if-then()"
    );
    assertEqualU32(
        loop0_asX2DifX2Delse(&instance),
        2u,
        "as-if-else()"
    );
    assertEqualU32(
        loop0_asX2Dbr_ifX2Dfirst(&instance),
        1u,
        "as-br_if-first()"
    );
    assertEqualU32(
        loop0_asX2Dbr_ifX2Dlast(&instance),
        2u,
        "as-br_if-last()"
    );
    assertEqualU32(
        loop0_asX2Dbr_tableX2Dfirst(&instance),
        1u,
        "as-br_table-first()"
    );
    assertEqualU32(
        loop0_asX2Dbr_tableX2Dlast(&instance),
        2u,
        "as-br_table-last()"
    );
    assertEqualU32(
        loop0_asX2Dcall_indirectX2Dfirst(&instance),
        1u,
        "as-call_indirect-first()"
    );
    assertEqualU32(
        loop0_asX2Dcall_indirectX2Dmid(&instance),
        2u,
        "as-call_indirect-mid()"
    );
    assertEqualU32(
        loop0_asX2Dcall_indirectX2Dlast(&instance),
        1u,
        "as-call_indirect-last()"
    );
    loop0_asX2DstoreX2Dfirst(&instance);
    loop0_asX2DstoreX2Dlast(&instance);
    assertEqualU32(
        loop0_asX2DmemoryX2EgrowX2Dvalue(&instance),
        1u,
        "as-memory.grow-value()"
    );
    assertEqualU32(
        loop0_asX2DcallX2Dvalue(&instance),
        1u,
        "as-call-value()"
    );
    assertEqualU32(
        loop0_asX2DreturnX2Dvalue(&instance),
        1u,
        "as-return-value()"
    );
    loop0_asX2DdropX2Doperand(&instance);
    assertEqualU32(
        loop0_asX2DbrX2Dvalue(&instance),
        1u,
        "as-br-value()"
    );
    assertEqualU32(
        loop0_asX2DlocalX2EsetX2Dvalue(&instance),
        1u,
        "as-local.set-value()"
    );
    assertEqualU32(
        loop0_asX2DlocalX2EteeX2Dvalue(&instance),
        1u,
        "as-local.tee-value()"
    );
    assertEqualU32(
        loop0_asX2DglobalX2EsetX2Dvalue(&instance),
        1u,
        "as-global.set-value()"
    );
    assertEqualU32(
        loop0_asX2DloadX2Doperand(&instance),
        1u,
        "as-load-operand()"
    );
    assertEqualU32(
        loop0_asX2DunaryX2Doperand(&instance),
        0u,
        "as-unary-operand()"
    );
    assertEqualU32(
        loop0_asX2DbinaryX2Doperand(&instance),
        12u,
        "as-binary-operand()"
    );
    assertEqualU32(
        loop0_asX2DtestX2Doperand(&instance),
        0u,
        "as-test-operand()"
    );
    assertEqualU32(
        loop0_asX2DcompareX2Doperand(&instance),
        0u,
        "as-compare-operand()"
    );
    assertEqualU32(
        loop0_breakX2Dbare(&instance),
        19u,
        "break-bare()"
    );
    assertEqualU32(
        loop0_breakX2Dinner(&instance),
        31u,
        "break-inner()"
    );
    assertEqualU32(
        loop0_effects(&instance),
        1u,
        "effects()"
    );
    assertEqualU64(
        loop0_while(&instance, 0ull),
        1ull,
        "while(0ull)"
    );
    assertEqualU64(
        loop0_while(&instance, 1ull),
        1ull,
        "while(1ull)"
    );
    assertEqualU64(
        loop0_while(&instance, 2ull),
        2ull,
        "while(2ull)"
    );
    assertEqualU64(
        loop0_while(&instance, 3ull),
        6ull,
        "while(3ull)"
    );
    assertEqualU64(
        loop0_while(&instance, 5ull),
        120ull,
        "while(5ull)"
    );
    assertEqualU64(
        loop0_while(&instance, 20ull),
        2432902008176640000ull,
        "while(20ull)"
    );
    assertEqualU64(
        loop0_for(&instance, 0ull),
        1ull,
        "for(0ull)"
    );
    assertEqualU64(
        loop0_for(&instance, 1ull),
        1ull,
        "for(1ull)"
    );
    assertEqualU64(
        loop0_for(&instance, 2ull),
        2ull,
        "for(2ull)"
    );
    assertEqualU64(
        loop0_for(&instance, 3ull),
        6ull,
        "for(3ull)"
    );
    assertEqualU64(
        loop0_for(&instance, 5ull),
        120ull,
        "for(5ull)"
    );
    assertEqualU64(
        loop0_for(&instance, 20ull),
        2432902008176640000ull,
        "for(20ull)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 0.0, 7.0),
        0.0,
        "nesting(0.0, 7.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 7.0, 0.0),
        0.0,
        "nesting(7.0, 0.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 1.0, 1.0),
        1.0,
        "nesting(1.0, 1.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 1.0, 2.0),
        2.0,
        "nesting(1.0, 2.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 1.0, 3.0),
        4.0,
        "nesting(1.0, 3.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 1.0, 4.0),
        6.0,
        "nesting(1.0, 4.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 1.0, 100.0),
        2550.0,
        "nesting(1.0, 100.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 1.0, 101.0),
        2601.0,
        "nesting(1.0, 101.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 2.0, 1.0),
        1.0,
        "nesting(2.0, 1.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 3.0, 1.0),
        1.0,
        "nesting(3.0, 1.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 10.0, 1.0),
        1.0,
        "nesting(10.0, 1.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 2.0, 2.0),
        3.0,
        "nesting(2.0, 2.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 2.0, 3.0),
        4.0,
        "nesting(2.0, 3.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 7.0, 4.0),
        10.309523582458496,
        "nesting(7.0, 4.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 7.0, 100.0),
        4381.5478515625,
        "nesting(7.0, 100.0)"
    );
    assertEqualF32(
        loop0_nesting(&instance, 7.0, 101.0),
        2601.0,
        "nesting(7.0, 101.0)"
    );
}
