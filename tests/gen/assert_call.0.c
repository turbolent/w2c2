
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_call.0.h"

void test() {
    call0Instance instance;
    call0Instantiate(&instance, resolveTestImports);
    printStart("call.0.wasm");
    assertEqualU32(
        call0_typeX2Di32(&instance),
        306u,
        "type-i32()"
    );
    assertEqualU64(
        call0_typeX2Di64(&instance),
        356ull,
        "type-i64()"
    );
    assertEqualF32(
        call0_typeX2Df32(&instance),
        3890.0,
        "type-f32()"
    );
    assertEqualF64(
        call0_typeX2Df64(&instance),
        3940.0,
        "type-f64()"
    );
    assertEqualU32(
        call0_typeX2DfirstX2Di32(&instance),
        32u,
        "type-first-i32()"
    );
    assertEqualU64(
        call0_typeX2DfirstX2Di64(&instance),
        64ull,
        "type-first-i64()"
    );
    assertEqualF32(
        call0_typeX2DfirstX2Df32(&instance),
        1.3200000524520874,
        "type-first-f32()"
    );
    assertEqualF64(
        call0_typeX2DfirstX2Df64(&instance),
        1.64,
        "type-first-f64()"
    );
    assertEqualU32(
        call0_typeX2DsecondX2Di32(&instance),
        32u,
        "type-second-i32()"
    );
    assertEqualU64(
        call0_typeX2DsecondX2Di64(&instance),
        64ull,
        "type-second-i64()"
    );
    assertEqualF32(
        call0_typeX2DsecondX2Df32(&instance),
        32.0,
        "type-second-f32()"
    );
    assertEqualF64(
        call0_typeX2DsecondX2Df64(&instance),
        64.1,
        "type-second-f64()"
    );
    assertEqualU64(
        call0_fac(&instance, 0ull),
        1ull,
        "fac(0ull)"
    );
    assertEqualU64(
        call0_fac(&instance, 1ull),
        1ull,
        "fac(1ull)"
    );
    assertEqualU64(
        call0_fac(&instance, 5ull),
        120ull,
        "fac(5ull)"
    );
    assertEqualU64(
        call0_fac(&instance, 25ull),
        7034535277573963776ull,
        "fac(25ull)"
    );
    assertEqualU64(
        call0_facX2Dacc(&instance, 0ull, 1ull),
        1ull,
        "fac-acc(0ull, 1ull)"
    );
    assertEqualU64(
        call0_facX2Dacc(&instance, 1ull, 1ull),
        1ull,
        "fac-acc(1ull, 1ull)"
    );
    assertEqualU64(
        call0_facX2Dacc(&instance, 5ull, 1ull),
        120ull,
        "fac-acc(5ull, 1ull)"
    );
    assertEqualU64(
        call0_facX2Dacc(&instance, 25ull, 1ull),
        7034535277573963776ull,
        "fac-acc(25ull, 1ull)"
    );
    assertEqualU64(
        call0_fib(&instance, 0ull),
        1ull,
        "fib(0ull)"
    );
    assertEqualU64(
        call0_fib(&instance, 1ull),
        1ull,
        "fib(1ull)"
    );
    assertEqualU64(
        call0_fib(&instance, 2ull),
        2ull,
        "fib(2ull)"
    );
    assertEqualU64(
        call0_fib(&instance, 5ull),
        8ull,
        "fib(5ull)"
    );
    assertEqualU64(
        call0_fib(&instance, 20ull),
        10946ull,
        "fib(20ull)"
    );
    assertEqualU32(
        call0_even(&instance, 0ull),
        44u,
        "even(0ull)"
    );
    assertEqualU32(
        call0_even(&instance, 1ull),
        99u,
        "even(1ull)"
    );
    assertEqualU32(
        call0_even(&instance, 100ull),
        44u,
        "even(100ull)"
    );
    assertEqualU32(
        call0_even(&instance, 77ull),
        99u,
        "even(77ull)"
    );
    assertEqualU32(
        call0_odd(&instance, 0ull),
        99u,
        "odd(0ull)"
    );
    assertEqualU32(
        call0_odd(&instance, 1ull),
        44u,
        "odd(1ull)"
    );
    assertEqualU32(
        call0_odd(&instance, 200ull),
        99u,
        "odd(200ull)"
    );
    assertEqualU32(
        call0_odd(&instance, 77ull),
        44u,
        "odd(77ull)"
    );
    assertEqualU32(
        call0_asX2DselectX2Dfirst(&instance),
        306u,
        "as-select-first()"
    );
    assertEqualU32(
        call0_asX2DselectX2Dmid(&instance),
        2u,
        "as-select-mid()"
    );
    assertEqualU32(
        call0_asX2DselectX2Dlast(&instance),
        2u,
        "as-select-last()"
    );
    assertEqualU32(
        call0_asX2DifX2Dcondition(&instance),
        1u,
        "as-if-condition()"
    );
    assertEqualU32(
        call0_asX2DbrX5FifX2Dfirst(&instance),
        306u,
        "as-br_if-first()"
    );
    assertEqualU32(
        call0_asX2DbrX5FifX2Dlast(&instance),
        2u,
        "as-br_if-last()"
    );
    assertEqualU32(
        call0_asX2DbrX5FtableX2Dfirst(&instance),
        306u,
        "as-br_table-first()"
    );
    assertEqualU32(
        call0_asX2DbrX5FtableX2Dlast(&instance),
        2u,
        "as-br_table-last()"
    );
    assertEqualU32(
        call0_asX2DcallX5FindirectX2Dfirst(&instance),
        306u,
        "as-call_indirect-first()"
    );
    assertEqualU32(
        call0_asX2DcallX5FindirectX2Dmid(&instance),
        2u,
        "as-call_indirect-mid()"
    );
    call0_asX2DstoreX2Dfirst(&instance);
    call0_asX2DstoreX2Dlast(&instance);
    assertEqualU32(
        call0_asX2DmemoryX2EgrowX2Dvalue(&instance),
        1u,
        "as-memory.grow-value()"
    );
    assertEqualU32(
        call0_asX2DreturnX2Dvalue(&instance),
        306u,
        "as-return-value()"
    );
    call0_asX2DdropX2Doperand(&instance);
    assertEqualU32(
        call0_asX2DbrX2Dvalue(&instance),
        306u,
        "as-br-value()"
    );
    assertEqualU32(
        call0_asX2DlocalX2EsetX2Dvalue(&instance),
        306u,
        "as-local.set-value()"
    );
    assertEqualU32(
        call0_asX2DlocalX2EteeX2Dvalue(&instance),
        306u,
        "as-local.tee-value()"
    );
    assertEqualU32(
        call0_asX2DglobalX2EsetX2Dvalue(&instance),
        306u,
        "as-global.set-value()"
    );
    assertEqualU32(
        call0_asX2DloadX2Doperand(&instance),
        1u,
        "as-load-operand()"
    );
    assertEqualF32(
        call0_asX2DunaryX2Doperand(&instance),
        0.0,
        "as-unary-operand()"
    );
    assertEqualU32(
        call0_asX2DbinaryX2Dleft(&instance),
        11u,
        "as-binary-left()"
    );
    assertEqualU32(
        call0_asX2DbinaryX2Dright(&instance),
        9u,
        "as-binary-right()"
    );
    assertEqualU32(
        call0_asX2DtestX2Doperand(&instance),
        0u,
        "as-test-operand()"
    );
    assertEqualU32(
        call0_asX2DcompareX2Dleft(&instance),
        1u,
        "as-compare-left()"
    );
    assertEqualU32(
        call0_asX2DcompareX2Dright(&instance),
        1u,
        "as-compare-right()"
    );
    assertEqualU64(
        call0_asX2DconvertX2Doperand(&instance),
        1ull,
        "as-convert-operand()"
    );
    assertEqualU32(
        call0_returnX2DfromX2DlongX2DargumentX2Dlist(&instance, 42u),
        42u,
        "return-from-long-argument-list(42u)"
    );
}
