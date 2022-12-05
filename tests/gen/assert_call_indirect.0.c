
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_call_indirect.0.h"

void test() {
    callindirect0Instance instance;
    callindirect0Instantiate(&instance, resolveTestImports);
    printStart("call_indirect.0.wasm");
    assertEqualU32(
        callindirect0_typeX2Di32(&instance),
        306u,
        "type-i32()"
    );
    assertEqualU64(
        callindirect0_typeX2Di64(&instance),
        356ull,
        "type-i64()"
    );
    assertEqualF32(
        callindirect0_typeX2Df32(&instance),
        3890.0,
        "type-f32()"
    );
    assertEqualF64(
        callindirect0_typeX2Df64(&instance),
        3940.0,
        "type-f64()"
    );
    assertEqualU64(
        callindirect0_typeX2Dindex(&instance),
        100ull,
        "type-index()"
    );
    assertEqualU32(
        callindirect0_typeX2DfirstX2Di32(&instance),
        32u,
        "type-first-i32()"
    );
    assertEqualU64(
        callindirect0_typeX2DfirstX2Di64(&instance),
        64ull,
        "type-first-i64()"
    );
    assertEqualF32(
        callindirect0_typeX2DfirstX2Df32(&instance),
        1.3200000524520874,
        "type-first-f32()"
    );
    assertEqualF64(
        callindirect0_typeX2DfirstX2Df64(&instance),
        1.64,
        "type-first-f64()"
    );
    assertEqualU32(
        callindirect0_typeX2DsecondX2Di32(&instance),
        32u,
        "type-second-i32()"
    );
    assertEqualU64(
        callindirect0_typeX2DsecondX2Di64(&instance),
        64ull,
        "type-second-i64()"
    );
    assertEqualF32(
        callindirect0_typeX2DsecondX2Df32(&instance),
        32.0,
        "type-second-f32()"
    );
    assertEqualF64(
        callindirect0_typeX2DsecondX2Df64(&instance),
        64.1,
        "type-second-f64()"
    );
    assertEqualU64(
        callindirect0_dispatch(&instance, 5u, 2ull),
        2ull,
        "dispatch(5u, 2ull)"
    );
    assertEqualU64(
        callindirect0_dispatch(&instance, 5u, 5ull),
        5ull,
        "dispatch(5u, 5ull)"
    );
    assertEqualU64(
        callindirect0_dispatch(&instance, 12u, 5ull),
        120ull,
        "dispatch(12u, 5ull)"
    );
    assertEqualU64(
        callindirect0_dispatch(&instance, 13u, 5ull),
        8ull,
        "dispatch(13u, 5ull)"
    );
    assertEqualU64(
        callindirect0_dispatch(&instance, 20u, 2ull),
        2ull,
        "dispatch(20u, 2ull)"
    );
    assertEqualU64(
        callindirect0_dispatchX2DstructuralX2Di64(&instance, 5u),
        9ull,
        "dispatch-structural-i64(5u)"
    );
    assertEqualU64(
        callindirect0_dispatchX2DstructuralX2Di64(&instance, 12u),
        362880ull,
        "dispatch-structural-i64(12u)"
    );
    assertEqualU64(
        callindirect0_dispatchX2DstructuralX2Di64(&instance, 13u),
        55ull,
        "dispatch-structural-i64(13u)"
    );
    assertEqualU64(
        callindirect0_dispatchX2DstructuralX2Di64(&instance, 20u),
        9ull,
        "dispatch-structural-i64(20u)"
    );
    assertEqualU32(
        callindirect0_dispatchX2DstructuralX2Di32(&instance, 4u),
        9u,
        "dispatch-structural-i32(4u)"
    );
    assertEqualU32(
        callindirect0_dispatchX2DstructuralX2Di32(&instance, 23u),
        362880u,
        "dispatch-structural-i32(23u)"
    );
    assertEqualU32(
        callindirect0_dispatchX2DstructuralX2Di32(&instance, 26u),
        55u,
        "dispatch-structural-i32(26u)"
    );
    assertEqualU32(
        callindirect0_dispatchX2DstructuralX2Di32(&instance, 19u),
        9u,
        "dispatch-structural-i32(19u)"
    );
    assertEqualF32(
        callindirect0_dispatchX2DstructuralX2Df32(&instance, 6u),
        9.0,
        "dispatch-structural-f32(6u)"
    );
    assertEqualF32(
        callindirect0_dispatchX2DstructuralX2Df32(&instance, 24u),
        362880.0,
        "dispatch-structural-f32(24u)"
    );
    assertEqualF32(
        callindirect0_dispatchX2DstructuralX2Df32(&instance, 27u),
        55.0,
        "dispatch-structural-f32(27u)"
    );
    assertEqualF32(
        callindirect0_dispatchX2DstructuralX2Df32(&instance, 21u),
        9.0,
        "dispatch-structural-f32(21u)"
    );
    assertEqualF64(
        callindirect0_dispatchX2DstructuralX2Df64(&instance, 7u),
        9.0,
        "dispatch-structural-f64(7u)"
    );
    assertEqualF64(
        callindirect0_dispatchX2DstructuralX2Df64(&instance, 25u),
        362880.0,
        "dispatch-structural-f64(25u)"
    );
    assertEqualF64(
        callindirect0_dispatchX2DstructuralX2Df64(&instance, 28u),
        55.0,
        "dispatch-structural-f64(28u)"
    );
    assertEqualF64(
        callindirect0_dispatchX2DstructuralX2Df64(&instance, 22u),
        9.0,
        "dispatch-structural-f64(22u)"
    );
    assertEqualU64(
        callindirect0_facX2Di64(&instance, 0ull),
        1ull,
        "fac-i64(0ull)"
    );
    assertEqualU64(
        callindirect0_facX2Di64(&instance, 1ull),
        1ull,
        "fac-i64(1ull)"
    );
    assertEqualU64(
        callindirect0_facX2Di64(&instance, 5ull),
        120ull,
        "fac-i64(5ull)"
    );
    assertEqualU64(
        callindirect0_facX2Di64(&instance, 25ull),
        7034535277573963776ull,
        "fac-i64(25ull)"
    );
    assertEqualU32(
        callindirect0_facX2Di32(&instance, 0u),
        1u,
        "fac-i32(0u)"
    );
    assertEqualU32(
        callindirect0_facX2Di32(&instance, 1u),
        1u,
        "fac-i32(1u)"
    );
    assertEqualU32(
        callindirect0_facX2Di32(&instance, 5u),
        120u,
        "fac-i32(5u)"
    );
    assertEqualU32(
        callindirect0_facX2Di32(&instance, 10u),
        3628800u,
        "fac-i32(10u)"
    );
    assertEqualF32(
        callindirect0_facX2Df32(&instance, 0.0),
        1.0,
        "fac-f32(0.0)"
    );
    assertEqualF32(
        callindirect0_facX2Df32(&instance, 1.0),
        1.0,
        "fac-f32(1.0)"
    );
    assertEqualF32(
        callindirect0_facX2Df32(&instance, 5.0),
        120.0,
        "fac-f32(5.0)"
    );
    assertEqualF32(
        callindirect0_facX2Df32(&instance, 10.0),
        3628800.0,
        "fac-f32(10.0)"
    );
    assertEqualF64(
        callindirect0_facX2Df64(&instance, 0.0),
        1.0,
        "fac-f64(0.0)"
    );
    assertEqualF64(
        callindirect0_facX2Df64(&instance, 1.0),
        1.0,
        "fac-f64(1.0)"
    );
    assertEqualF64(
        callindirect0_facX2Df64(&instance, 5.0),
        120.0,
        "fac-f64(5.0)"
    );
    assertEqualF64(
        callindirect0_facX2Df64(&instance, 10.0),
        3628800.0,
        "fac-f64(10.0)"
    );
    assertEqualU64(
        callindirect0_fibX2Di64(&instance, 0ull),
        1ull,
        "fib-i64(0ull)"
    );
    assertEqualU64(
        callindirect0_fibX2Di64(&instance, 1ull),
        1ull,
        "fib-i64(1ull)"
    );
    assertEqualU64(
        callindirect0_fibX2Di64(&instance, 2ull),
        2ull,
        "fib-i64(2ull)"
    );
    assertEqualU64(
        callindirect0_fibX2Di64(&instance, 5ull),
        8ull,
        "fib-i64(5ull)"
    );
    assertEqualU64(
        callindirect0_fibX2Di64(&instance, 20ull),
        10946ull,
        "fib-i64(20ull)"
    );
    assertEqualU32(
        callindirect0_fibX2Di32(&instance, 0u),
        1u,
        "fib-i32(0u)"
    );
    assertEqualU32(
        callindirect0_fibX2Di32(&instance, 1u),
        1u,
        "fib-i32(1u)"
    );
    assertEqualU32(
        callindirect0_fibX2Di32(&instance, 2u),
        2u,
        "fib-i32(2u)"
    );
    assertEqualU32(
        callindirect0_fibX2Di32(&instance, 5u),
        8u,
        "fib-i32(5u)"
    );
    assertEqualU32(
        callindirect0_fibX2Di32(&instance, 20u),
        10946u,
        "fib-i32(20u)"
    );
    assertEqualF32(
        callindirect0_fibX2Df32(&instance, 0.0),
        1.0,
        "fib-f32(0.0)"
    );
    assertEqualF32(
        callindirect0_fibX2Df32(&instance, 1.0),
        1.0,
        "fib-f32(1.0)"
    );
    assertEqualF32(
        callindirect0_fibX2Df32(&instance, 2.0),
        2.0,
        "fib-f32(2.0)"
    );
    assertEqualF32(
        callindirect0_fibX2Df32(&instance, 5.0),
        8.0,
        "fib-f32(5.0)"
    );
    assertEqualF32(
        callindirect0_fibX2Df32(&instance, 20.0),
        10946.0,
        "fib-f32(20.0)"
    );
    assertEqualF64(
        callindirect0_fibX2Df64(&instance, 0.0),
        1.0,
        "fib-f64(0.0)"
    );
    assertEqualF64(
        callindirect0_fibX2Df64(&instance, 1.0),
        1.0,
        "fib-f64(1.0)"
    );
    assertEqualF64(
        callindirect0_fibX2Df64(&instance, 2.0),
        2.0,
        "fib-f64(2.0)"
    );
    assertEqualF64(
        callindirect0_fibX2Df64(&instance, 5.0),
        8.0,
        "fib-f64(5.0)"
    );
    assertEqualF64(
        callindirect0_fibX2Df64(&instance, 20.0),
        10946.0,
        "fib-f64(20.0)"
    );
    assertEqualU32(
        callindirect0_even(&instance, 0u),
        44u,
        "even(0u)"
    );
    assertEqualU32(
        callindirect0_even(&instance, 1u),
        99u,
        "even(1u)"
    );
    assertEqualU32(
        callindirect0_even(&instance, 100u),
        44u,
        "even(100u)"
    );
    assertEqualU32(
        callindirect0_even(&instance, 77u),
        99u,
        "even(77u)"
    );
    assertEqualU32(
        callindirect0_odd(&instance, 0u),
        99u,
        "odd(0u)"
    );
    assertEqualU32(
        callindirect0_odd(&instance, 1u),
        44u,
        "odd(1u)"
    );
    assertEqualU32(
        callindirect0_odd(&instance, 200u),
        99u,
        "odd(200u)"
    );
    assertEqualU32(
        callindirect0_odd(&instance, 77u),
        44u,
        "odd(77u)"
    );
    assertEqualU32(
        callindirect0_asX2DselectX2Dfirst(&instance),
        306u,
        "as-select-first()"
    );
    assertEqualU32(
        callindirect0_asX2DselectX2Dmid(&instance),
        2u,
        "as-select-mid()"
    );
    assertEqualU32(
        callindirect0_asX2DselectX2Dlast(&instance),
        2u,
        "as-select-last()"
    );
    assertEqualU32(
        callindirect0_asX2DifX2Dcondition(&instance),
        1u,
        "as-if-condition()"
    );
    assertEqualU64(
        callindirect0_asX2DbrX5FifX2Dfirst(&instance),
        356ull,
        "as-br_if-first()"
    );
    assertEqualU32(
        callindirect0_asX2DbrX5FifX2Dlast(&instance),
        2u,
        "as-br_if-last()"
    );
    assertEqualF32(
        callindirect0_asX2DbrX5FtableX2Dfirst(&instance),
        3890.0,
        "as-br_table-first()"
    );
    assertEqualU32(
        callindirect0_asX2DbrX5FtableX2Dlast(&instance),
        2u,
        "as-br_table-last()"
    );
    callindirect0_asX2DstoreX2Dfirst(&instance);
    callindirect0_asX2DstoreX2Dlast(&instance);
    assertEqualU32(
        callindirect0_asX2DmemoryX2EgrowX2Dvalue(&instance),
        1u,
        "as-memory.grow-value()"
    );
    assertEqualU32(
        callindirect0_asX2DreturnX2Dvalue(&instance),
        1u,
        "as-return-value()"
    );
    callindirect0_asX2DdropX2Doperand(&instance);
    assertEqualF32(
        callindirect0_asX2DbrX2Dvalue(&instance),
        1.0,
        "as-br-value()"
    );
    assertEqualF64(
        callindirect0_asX2DlocalX2EsetX2Dvalue(&instance),
        1.0,
        "as-local.set-value()"
    );
    assertEqualF64(
        callindirect0_asX2DlocalX2EteeX2Dvalue(&instance),
        1.0,
        "as-local.tee-value()"
    );
    assertEqualF64(
        callindirect0_asX2DglobalX2EsetX2Dvalue(&instance),
        1.0,
        "as-global.set-value()"
    );
    assertEqualU32(
        callindirect0_asX2DloadX2Doperand(&instance),
        1u,
        "as-load-operand()"
    );
    assertEqualF32(
        callindirect0_asX2DunaryX2Doperand(&instance),
        0.0,
        "as-unary-operand()"
    );
    assertEqualU32(
        callindirect0_asX2DbinaryX2Dleft(&instance),
        11u,
        "as-binary-left()"
    );
    assertEqualU32(
        callindirect0_asX2DbinaryX2Dright(&instance),
        9u,
        "as-binary-right()"
    );
    assertEqualU32(
        callindirect0_asX2DtestX2Doperand(&instance),
        0u,
        "as-test-operand()"
    );
    assertEqualU32(
        callindirect0_asX2DcompareX2Dleft(&instance),
        1u,
        "as-compare-left()"
    );
    assertEqualU32(
        callindirect0_asX2DcompareX2Dright(&instance),
        1u,
        "as-compare-right()"
    );
    assertEqualU64(
        callindirect0_asX2DconvertX2Doperand(&instance),
        1ull,
        "as-convert-operand()"
    );
}
