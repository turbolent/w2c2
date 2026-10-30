#include "test.h"
#include "test_loop.0.h"

void test(void) {
    static m6_loopX2E0Instance instance;
    m6_loopX2E0Instantiate(&instance, resolveTestImports);
    printStart("loop.0.wasm");
    (void)(m6_loopX2E0Export5_empty(&instance));
    assertEqualU32(
        m6_loopX2E0Export8_singular(&instance),
        7u,
        "singular()"
    );
    assertEqualU32(
        m6_loopX2E0Export5_multi(&instance),
        8u,
        "multi()"
    );
    assertEqualU32(
        m6_loopX2E0Export6_nested(&instance),
        9u,
        "nested()"
    );
    assertEqualU32(
        m6_loopX2E0Export4_deep(&instance),
        150u,
        "deep()"
    );
    assertEqualU32(
        m6_loopX2E0Export15_asX2DselectX2Dfirst(&instance),
        1u,
        "as-select-first()"
    );
    assertEqualU32(
        m6_loopX2E0Export13_asX2DselectX2Dmid(&instance),
        2u,
        "as-select-mid()"
    );
    assertEqualU32(
        m6_loopX2E0Export14_asX2DselectX2Dlast(&instance),
        2u,
        "as-select-last()"
    );
    (void)(m6_loopX2E0Export15_asX2DifX2Dcondition(&instance));
    assertEqualU32(
        m6_loopX2E0Export10_asX2DifX2Dthen(&instance),
        1u,
        "as-if-then()"
    );
    assertEqualU32(
        m6_loopX2E0Export10_asX2DifX2Delse(&instance),
        2u,
        "as-if-else()"
    );
    assertEqualU32(
        m6_loopX2E0Export14_asX2DbrX5FifX2Dfirst(&instance),
        1u,
        "as-br_if-first()"
    );
    assertEqualU32(
        m6_loopX2E0Export13_asX2DbrX5FifX2Dlast(&instance),
        2u,
        "as-br_if-last()"
    );
    assertEqualU32(
        m6_loopX2E0Export17_asX2DbrX5FtableX2Dfirst(&instance),
        1u,
        "as-br_table-first()"
    );
    assertEqualU32(
        m6_loopX2E0Export16_asX2DbrX5FtableX2Dlast(&instance),
        2u,
        "as-br_table-last()"
    );
    assertEqualU32(
        m6_loopX2E0Export22_asX2DcallX5FindirectX2Dfirst(&instance),
        1u,
        "as-call_indirect-first()"
    );
    assertEqualU32(
        m6_loopX2E0Export20_asX2DcallX5FindirectX2Dmid(&instance),
        2u,
        "as-call_indirect-mid()"
    );
    assertEqualU32(
        m6_loopX2E0Export21_asX2DcallX5FindirectX2Dlast(&instance),
        1u,
        "as-call_indirect-last()"
    );
    (void)(m6_loopX2E0Export14_asX2DstoreX2Dfirst(&instance));
    (void)(m6_loopX2E0Export13_asX2DstoreX2Dlast(&instance));
    assertEqualU32(
        m6_loopX2E0Export20_asX2DmemoryX2EgrowX2Dvalue(&instance),
        1u,
        "as-memory.grow-value()"
    );
    assertEqualU32(
        m6_loopX2E0Export13_asX2DcallX2Dvalue(&instance),
        1u,
        "as-call-value()"
    );
    assertEqualU32(
        m6_loopX2E0Export15_asX2DreturnX2Dvalue(&instance),
        1u,
        "as-return-value()"
    );
    (void)(m6_loopX2E0Export15_asX2DdropX2Doperand(&instance));
    assertEqualU32(
        m6_loopX2E0Export11_asX2DbrX2Dvalue(&instance),
        1u,
        "as-br-value()"
    );
    assertEqualU32(
        m6_loopX2E0Export18_asX2DlocalX2EsetX2Dvalue(&instance),
        1u,
        "as-local.set-value()"
    );
    assertEqualU32(
        m6_loopX2E0Export18_asX2DlocalX2EteeX2Dvalue(&instance),
        1u,
        "as-local.tee-value()"
    );
    assertEqualU32(
        m6_loopX2E0Export19_asX2DglobalX2EsetX2Dvalue(&instance),
        1u,
        "as-global.set-value()"
    );
    assertEqualU32(
        m6_loopX2E0Export15_asX2DloadX2Doperand(&instance),
        1u,
        "as-load-operand()"
    );
    assertEqualU32(
        m6_loopX2E0Export16_asX2DunaryX2Doperand(&instance),
        0u,
        "as-unary-operand()"
    );
    assertEqualU32(
        m6_loopX2E0Export17_asX2DbinaryX2Doperand(&instance),
        12u,
        "as-binary-operand()"
    );
    assertEqualU32(
        m6_loopX2E0Export15_asX2DtestX2Doperand(&instance),
        0u,
        "as-test-operand()"
    );
    assertEqualU32(
        m6_loopX2E0Export18_asX2DcompareX2Doperand(&instance),
        0u,
        "as-compare-operand()"
    );
    assertEqualU32(
        m6_loopX2E0Export18_asX2DbinaryX2Doperands(&instance),
        12u,
        "as-binary-operands()"
    );
    assertEqualU32(
        m6_loopX2E0Export19_asX2DcompareX2Doperands(&instance),
        0u,
        "as-compare-operands()"
    );
    assertEqualU32(
        m6_loopX2E0Export17_asX2DmixedX2Doperands(&instance),
        27u,
        "as-mixed-operands()"
    );
    assertEqualU32(
        m6_loopX2E0Export10_breakX2Dbare(&instance),
        19u,
        "break-bare()"
    );
    assertEqualU32(
        m6_loopX2E0Export11_breakX2Dvalue(&instance),
        18u,
        "break-value()"
    );
    {
        struct w2c2_result_iij result;
        result = m6_loopX2E0Export17_breakX2DmultiX2Dvalue(&instance);
        assertEqualU32(
            result.v0,
            18u,
            "break-multi-value() result 0"
        );
        assertEqualU32(
            result.v1,
            4294967278u,
            "break-multi-value() result 1"
        );
        assertEqualU64(
            result.v2,
            18ull,
            "break-multi-value() result 2"
        );
    }
    assertEqualU32(
        m6_loopX2E0Export14_breakX2Drepeated(&instance),
        18u,
        "break-repeated()"
    );
    assertEqualU32(
        m6_loopX2E0Export11_breakX2Dinner(&instance),
        31u,
        "break-inner()"
    );
    assertEqualU32(
        m6_loopX2E0Export5_param(&instance),
        3u,
        "param()"
    );
    assertEqualU32(
        m6_loopX2E0Export6_params(&instance),
        3u,
        "params()"
    );
    assertEqualU32(
        m6_loopX2E0Export9_paramsX2Did(&instance),
        3u,
        "params-id()"
    );
    assertEqualU32(
        m6_loopX2E0Export11_paramX2Dbreak(&instance),
        13u,
        "param-break()"
    );
    assertEqualU32(
        m6_loopX2E0Export12_paramsX2Dbreak(&instance),
        12u,
        "params-break()"
    );
    assertEqualU32(
        m6_loopX2E0Export15_paramsX2DidX2Dbreak(&instance),
        3u,
        "params-id-break()"
    );
    assertEqualU32(
        m6_loopX2E0Export7_effects(&instance),
        1u,
        "effects()"
    );
    assertEqualU64(
        m6_loopX2E0Export5_while(&instance, 0ull),
        1ull,
        "while(0ull)"
    );
    assertEqualU64(
        m6_loopX2E0Export5_while(&instance, 1ull),
        1ull,
        "while(1ull)"
    );
    assertEqualU64(
        m6_loopX2E0Export5_while(&instance, 2ull),
        2ull,
        "while(2ull)"
    );
    assertEqualU64(
        m6_loopX2E0Export5_while(&instance, 3ull),
        6ull,
        "while(3ull)"
    );
    assertEqualU64(
        m6_loopX2E0Export5_while(&instance, 5ull),
        120ull,
        "while(5ull)"
    );
    assertEqualU64(
        m6_loopX2E0Export5_while(&instance, 20ull),
        2432902008176640000ull,
        "while(20ull)"
    );
    assertEqualU64(
        m6_loopX2E0Export3_for(&instance, 0ull),
        1ull,
        "for(0ull)"
    );
    assertEqualU64(
        m6_loopX2E0Export3_for(&instance, 1ull),
        1ull,
        "for(1ull)"
    );
    assertEqualU64(
        m6_loopX2E0Export3_for(&instance, 2ull),
        2ull,
        "for(2ull)"
    );
    assertEqualU64(
        m6_loopX2E0Export3_for(&instance, 3ull),
        6ull,
        "for(3ull)"
    );
    assertEqualU64(
        m6_loopX2E0Export3_for(&instance, 5ull),
        120ull,
        "for(5ull)"
    );
    assertEqualU64(
        m6_loopX2E0Export3_for(&instance, 20ull),
        2432902008176640000ull,
        "for(20ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x00000000u), f32_reinterpret_i32(0x40e00000u))),
        0u,
        "nesting(0.0, 7.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x40e00000u), f32_reinterpret_i32(0x00000000u))),
        0u,
        "nesting(7.0, 0.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x3f800000u), f32_reinterpret_i32(0x3f800000u))),
        1065353216u,
        "nesting(1.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x3f800000u), f32_reinterpret_i32(0x40000000u))),
        1073741824u,
        "nesting(1.0, 2.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x3f800000u), f32_reinterpret_i32(0x40400000u))),
        1082130432u,
        "nesting(1.0, 3.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x3f800000u), f32_reinterpret_i32(0x40800000u))),
        1086324736u,
        "nesting(1.0, 4.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x3f800000u), f32_reinterpret_i32(0x42c80000u))),
        1159684096u,
        "nesting(1.0, 100.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x3f800000u), f32_reinterpret_i32(0x42ca0000u))),
        1159892992u,
        "nesting(1.0, 101.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x40000000u), f32_reinterpret_i32(0x3f800000u))),
        1065353216u,
        "nesting(2.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x40400000u), f32_reinterpret_i32(0x3f800000u))),
        1065353216u,
        "nesting(3.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x41200000u), f32_reinterpret_i32(0x3f800000u))),
        1065353216u,
        "nesting(10.0, 1.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x40000000u), f32_reinterpret_i32(0x40000000u))),
        1077936128u,
        "nesting(2.0, 2.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x40000000u), f32_reinterpret_i32(0x40400000u))),
        1082130432u,
        "nesting(2.0, 3.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x40e00000u), f32_reinterpret_i32(0x40800000u))),
        1092940751u,
        "nesting(7.0, 4.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x40e00000u), f32_reinterpret_i32(0x42c80000u))),
        1166601314u,
        "nesting(7.0, 100.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_loopX2E0Export7_nesting(&instance, f32_reinterpret_i32(0x40e00000u), f32_reinterpret_i32(0x42ca0000u))),
        1159892992u,
        "nesting(7.0, 101.0)"
    );
    (void)(m6_loopX2E0Export8_typeX2Duse(&instance));
    assertEqualU32(
        m6_loopX2E0Export16_brX2DimplicitX2Ddrop(&instance),
        1u,
        "br-implicit-drop()"
    );
    m6_loopX2E0FreeInstance(&instance);
}
