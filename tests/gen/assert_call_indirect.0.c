
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_call_indirect.0.h"

void test() {
    m15_callX5FindirectX2E0Instance instance;
    m15_callX5FindirectX2E0Instantiate(&instance, resolveTestImports);
    printStart("call_indirect.0.wasm");
    assertEqualU32(
        m15_callX5FindirectX2E0Export8_typeX2Di32(&instance),
        306u,
        "type-i32()"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export8_typeX2Di64(&instance),
        356ull,
        "type-i64()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export8_typeX2Df32(&instance)),
        1165172736u,
        "type-f32()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export8_typeX2Df64(&instance)),
        4660882566700597248ull,
        "type-f64()"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export10_typeX2Dindex(&instance),
        100ull,
        "type-index()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export14_typeX2DfirstX2Di32(&instance),
        32u,
        "type-first-i32()"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export14_typeX2DfirstX2Di64(&instance),
        64ull,
        "type-first-i64()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export14_typeX2DfirstX2Df32(&instance)),
        1068037571u,
        "type-first-f32()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export14_typeX2DfirstX2Df64(&instance)),
        4610064722561534525ull,
        "type-first-f64()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export15_typeX2DsecondX2Di32(&instance),
        32u,
        "type-second-i32()"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export15_typeX2DsecondX2Di64(&instance),
        64ull,
        "type-second-i64()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export15_typeX2DsecondX2Df32(&instance)),
        1107296256u,
        "type-second-f32()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export15_typeX2DsecondX2Df64(&instance)),
        4634211053438658150ull,
        "type-second-f64()"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export8_dispatch(&instance, 5u, 2ull),
        2ull,
        "dispatch(5u, 2ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export8_dispatch(&instance, 5u, 5ull),
        5ull,
        "dispatch(5u, 5ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export8_dispatch(&instance, 12u, 5ull),
        120ull,
        "dispatch(12u, 5ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export8_dispatch(&instance, 13u, 5ull),
        8ull,
        "dispatch(13u, 5ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export8_dispatch(&instance, 20u, 2ull),
        2ull,
        "dispatch(20u, 2ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Di64(&instance, 5u),
        9ull,
        "dispatch-structural-i64(5u)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Di64(&instance, 12u),
        362880ull,
        "dispatch-structural-i64(12u)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Di64(&instance, 13u),
        55ull,
        "dispatch-structural-i64(13u)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Di64(&instance, 20u),
        9ull,
        "dispatch-structural-i64(20u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Di32(&instance, 4u),
        9u,
        "dispatch-structural-i32(4u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Di32(&instance, 23u),
        362880u,
        "dispatch-structural-i32(23u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Di32(&instance, 26u),
        55u,
        "dispatch-structural-i32(26u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Di32(&instance, 19u),
        9u,
        "dispatch-structural-i32(19u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Df32(&instance, 6u)),
        1091567616u,
        "dispatch-structural-f32(6u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Df32(&instance, 24u)),
        1219571712u,
        "dispatch-structural-f32(24u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Df32(&instance, 27u)),
        1113325568u,
        "dispatch-structural-f32(27u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Df32(&instance, 21u)),
        1091567616u,
        "dispatch-structural-f32(21u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Df64(&instance, 7u)),
        4621256167635550208ull,
        "dispatch-structural-f64(7u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Df64(&instance, 25u)),
        4689977843394805760ull,
        "dispatch-structural-f64(25u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Df64(&instance, 28u)),
        4632937379169042432ull,
        "dispatch-structural-f64(28u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export23_dispatchX2DstructuralX2Df64(&instance, 22u)),
        4621256167635550208ull,
        "dispatch-structural-f64(22u)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export7_facX2Di64(&instance, 0ull),
        1ull,
        "fac-i64(0ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export7_facX2Di64(&instance, 1ull),
        1ull,
        "fac-i64(1ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export7_facX2Di64(&instance, 5ull),
        120ull,
        "fac-i64(5ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export7_facX2Di64(&instance, 25ull),
        7034535277573963776ull,
        "fac-i64(25ull)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export7_facX2Di32(&instance, 0u),
        1u,
        "fac-i32(0u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export7_facX2Di32(&instance, 1u),
        1u,
        "fac-i32(1u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export7_facX2Di32(&instance, 5u),
        120u,
        "fac-i32(5u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export7_facX2Di32(&instance, 10u),
        3628800u,
        "fac-i32(10u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export7_facX2Df32(&instance, 0.0)),
        1065353216u,
        "fac-f32(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export7_facX2Df32(&instance, 1.0)),
        1065353216u,
        "fac-f32(1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export7_facX2Df32(&instance, 5.0)),
        1123024896u,
        "fac-f32(5.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export7_facX2Df32(&instance, 10.0)),
        1247640576u,
        "fac-f32(10.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export7_facX2Df64(&instance, 0.0)),
        4607182418800017408ull,
        "fac-f64(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export7_facX2Df64(&instance, 1.0)),
        4607182418800017408ull,
        "fac-f64(1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export7_facX2Df64(&instance, 5.0)),
        4638144666238189568ull,
        "fac-f64(5.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export7_facX2Df64(&instance, 10.0)),
        4705047200009289728ull,
        "fac-f64(10.0)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export7_fibX2Di64(&instance, 0ull),
        1ull,
        "fib-i64(0ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export7_fibX2Di64(&instance, 1ull),
        1ull,
        "fib-i64(1ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export7_fibX2Di64(&instance, 2ull),
        2ull,
        "fib-i64(2ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export7_fibX2Di64(&instance, 5ull),
        8ull,
        "fib-i64(5ull)"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export7_fibX2Di64(&instance, 20ull),
        10946ull,
        "fib-i64(20ull)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export7_fibX2Di32(&instance, 0u),
        1u,
        "fib-i32(0u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export7_fibX2Di32(&instance, 1u),
        1u,
        "fib-i32(1u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export7_fibX2Di32(&instance, 2u),
        2u,
        "fib-i32(2u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export7_fibX2Di32(&instance, 5u),
        8u,
        "fib-i32(5u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export7_fibX2Di32(&instance, 20u),
        10946u,
        "fib-i32(20u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export7_fibX2Df32(&instance, 0.0)),
        1065353216u,
        "fib-f32(0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export7_fibX2Df32(&instance, 1.0)),
        1065353216u,
        "fib-f32(1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export7_fibX2Df32(&instance, 2.0)),
        1073741824u,
        "fib-f32(2.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export7_fibX2Df32(&instance, 5.0)),
        1090519040u,
        "fib-f32(5.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export7_fibX2Df32(&instance, 20.0)),
        1177225216u,
        "fib-f32(20.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export7_fibX2Df64(&instance, 0.0)),
        4607182418800017408ull,
        "fib-f64(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export7_fibX2Df64(&instance, 1.0)),
        4607182418800017408ull,
        "fib-f64(1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export7_fibX2Df64(&instance, 2.0)),
        4611686018427387904ull,
        "fib-f64(2.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export7_fibX2Df64(&instance, 5.0)),
        4620693217682128896ull,
        "fib-f64(5.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export7_fibX2Df64(&instance, 20.0)),
        4667243241467281408ull,
        "fib-f64(20.0)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export4_even(&instance, 0u),
        44u,
        "even(0u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export4_even(&instance, 1u),
        99u,
        "even(1u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export4_even(&instance, 100u),
        44u,
        "even(100u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export4_even(&instance, 77u),
        99u,
        "even(77u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export3_odd(&instance, 0u),
        99u,
        "odd(0u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export3_odd(&instance, 1u),
        44u,
        "odd(1u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export3_odd(&instance, 200u),
        99u,
        "odd(200u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export3_odd(&instance, 77u),
        44u,
        "odd(77u)"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export15_asX2DselectX2Dfirst(&instance),
        306u,
        "as-select-first()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export13_asX2DselectX2Dmid(&instance),
        2u,
        "as-select-mid()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export14_asX2DselectX2Dlast(&instance),
        2u,
        "as-select-last()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export15_asX2DifX2Dcondition(&instance),
        1u,
        "as-if-condition()"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export14_asX2DbrX5FifX2Dfirst(&instance),
        356ull,
        "as-br_if-first()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export13_asX2DbrX5FifX2Dlast(&instance),
        2u,
        "as-br_if-last()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export17_asX2DbrX5FtableX2Dfirst(&instance)),
        1165172736u,
        "as-br_table-first()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export16_asX2DbrX5FtableX2Dlast(&instance),
        2u,
        "as-br_table-last()"
    );
    m15_callX5FindirectX2E0Export14_asX2DstoreX2Dfirst(&instance);
    m15_callX5FindirectX2E0Export13_asX2DstoreX2Dlast(&instance);
    assertEqualU32(
        m15_callX5FindirectX2E0Export20_asX2DmemoryX2EgrowX2Dvalue(&instance),
        1u,
        "as-memory.grow-value()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export15_asX2DreturnX2Dvalue(&instance),
        1u,
        "as-return-value()"
    );
    m15_callX5FindirectX2E0Export15_asX2DdropX2Doperand(&instance);
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export11_asX2DbrX2Dvalue(&instance)),
        1065353216u,
        "as-br-value()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export18_asX2DlocalX2EsetX2Dvalue(&instance)),
        4607182418800017408ull,
        "as-local.set-value()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export18_asX2DlocalX2EteeX2Dvalue(&instance)),
        4607182418800017408ull,
        "as-local.tee-value()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m15_callX5FindirectX2E0Export19_asX2DglobalX2EsetX2Dvalue(&instance)),
        4607182418800017408ull,
        "as-global.set-value()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export15_asX2DloadX2Doperand(&instance),
        1u,
        "as-load-operand()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m15_callX5FindirectX2E0Export16_asX2DunaryX2Doperand(&instance)),
        0u,
        "as-unary-operand()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export14_asX2DbinaryX2Dleft(&instance),
        11u,
        "as-binary-left()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export15_asX2DbinaryX2Dright(&instance),
        9u,
        "as-binary-right()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export15_asX2DtestX2Doperand(&instance),
        0u,
        "as-test-operand()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export15_asX2DcompareX2Dleft(&instance),
        1u,
        "as-compare-left()"
    );
    assertEqualU32(
        m15_callX5FindirectX2E0Export16_asX2DcompareX2Dright(&instance),
        1u,
        "as-compare-right()"
    );
    assertEqualU64(
        m15_callX5FindirectX2E0Export18_asX2DconvertX2Doperand(&instance),
        1ull,
        "as-convert-operand()"
    );
}
