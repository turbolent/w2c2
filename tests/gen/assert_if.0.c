#include "test.h"
#include "test_if.0.h"

void test(void) {
    static m4_ifX2E0Instance instance;
    m4_ifX2E0Instantiate(&instance, resolveTestImports);
    printStart("if.0.wasm");
    (void)(m4_ifX2E0Export5_empty(&instance, 0u));
    (void)(m4_ifX2E0Export5_empty(&instance, 1u));
    (void)(m4_ifX2E0Export5_empty(&instance, 100u));
    (void)(m4_ifX2E0Export5_empty(&instance, 4294967294u));
    assertEqualU32(
        m4_ifX2E0Export8_singular(&instance, 0u),
        8u,
        "singular(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export8_singular(&instance, 1u),
        7u,
        "singular(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export8_singular(&instance, 10u),
        7u,
        "singular(10u)"
    );
    assertEqualU32(
        m4_ifX2E0Export8_singular(&instance, 4294967286u),
        7u,
        "singular(4294967286u)"
    );
    {
        struct w2c2_result_ii result;
        result = m4_ifX2E0Export5_multi(&instance, 0u);
        assertEqualU32(
            result.v0,
            9u,
            "multi(0u) result 0"
        );
        assertEqualU32(
            result.v1,
            4294967295u,
            "multi(0u) result 1"
        );
    }
    {
        struct w2c2_result_ii result;
        result = m4_ifX2E0Export5_multi(&instance, 1u);
        assertEqualU32(
            result.v0,
            8u,
            "multi(1u) result 0"
        );
        assertEqualU32(
            result.v1,
            1u,
            "multi(1u) result 1"
        );
    }
    {
        struct w2c2_result_ii result;
        result = m4_ifX2E0Export5_multi(&instance, 13u);
        assertEqualU32(
            result.v0,
            8u,
            "multi(13u) result 0"
        );
        assertEqualU32(
            result.v1,
            1u,
            "multi(13u) result 1"
        );
    }
    {
        struct w2c2_result_ii result;
        result = m4_ifX2E0Export5_multi(&instance, 4294967291u);
        assertEqualU32(
            result.v0,
            8u,
            "multi(4294967291u) result 0"
        );
        assertEqualU32(
            result.v1,
            1u,
            "multi(4294967291u) result 1"
        );
    }
    assertEqualU32(
        m4_ifX2E0Export6_nested(&instance, 0u, 0u),
        11u,
        "nested(0u, 0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export6_nested(&instance, 1u, 0u),
        10u,
        "nested(1u, 0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export6_nested(&instance, 0u, 1u),
        10u,
        "nested(0u, 1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export6_nested(&instance, 3u, 2u),
        9u,
        "nested(3u, 2u)"
    );
    assertEqualU32(
        m4_ifX2E0Export6_nested(&instance, 0u, 4294967196u),
        10u,
        "nested(0u, 4294967196u)"
    );
    assertEqualU32(
        m4_ifX2E0Export6_nested(&instance, 10u, 10u),
        9u,
        "nested(10u, 10u)"
    );
    assertEqualU32(
        m4_ifX2E0Export6_nested(&instance, 0u, 4294967295u),
        10u,
        "nested(0u, 4294967295u)"
    );
    assertEqualU32(
        m4_ifX2E0Export6_nested(&instance, 4294967185u, 4294967294u),
        9u,
        "nested(4294967185u, 4294967294u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_asX2DselectX2Dfirst(&instance, 0u),
        0u,
        "as-select-first(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_asX2DselectX2Dfirst(&instance, 1u),
        1u,
        "as-select-first(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export13_asX2DselectX2Dmid(&instance, 0u),
        2u,
        "as-select-mid(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export13_asX2DselectX2Dmid(&instance, 1u),
        2u,
        "as-select-mid(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export14_asX2DselectX2Dlast(&instance, 0u),
        3u,
        "as-select-last(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export14_asX2DselectX2Dlast(&instance, 1u),
        2u,
        "as-select-last(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export13_asX2DloopX2Dfirst(&instance, 0u),
        0u,
        "as-loop-first(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export13_asX2DloopX2Dfirst(&instance, 1u),
        1u,
        "as-loop-first(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export11_asX2DloopX2Dmid(&instance, 0u),
        0u,
        "as-loop-mid(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export11_asX2DloopX2Dmid(&instance, 1u),
        1u,
        "as-loop-mid(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export12_asX2DloopX2Dlast(&instance, 0u),
        0u,
        "as-loop-last(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export12_asX2DloopX2Dlast(&instance, 1u),
        1u,
        "as-loop-last(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_asX2DifX2Dcondition(&instance, 0u),
        3u,
        "as-if-condition(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_asX2DifX2Dcondition(&instance, 1u),
        2u,
        "as-if-condition(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export14_asX2DbrX5FifX2Dfirst(&instance, 0u),
        0u,
        "as-br_if-first(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export14_asX2DbrX5FifX2Dfirst(&instance, 1u),
        1u,
        "as-br_if-first(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export13_asX2DbrX5FifX2Dlast(&instance, 0u),
        3u,
        "as-br_if-last(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export13_asX2DbrX5FifX2Dlast(&instance, 1u),
        2u,
        "as-br_if-last(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export17_asX2DbrX5FtableX2Dfirst(&instance, 0u),
        0u,
        "as-br_table-first(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export17_asX2DbrX5FtableX2Dfirst(&instance, 1u),
        1u,
        "as-br_table-first(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export16_asX2DbrX5FtableX2Dlast(&instance, 0u),
        2u,
        "as-br_table-last(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export16_asX2DbrX5FtableX2Dlast(&instance, 1u),
        2u,
        "as-br_table-last(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export22_asX2DcallX5FindirectX2Dfirst(&instance, 0u),
        0u,
        "as-call_indirect-first(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export22_asX2DcallX5FindirectX2Dfirst(&instance, 1u),
        1u,
        "as-call_indirect-first(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export20_asX2DcallX5FindirectX2Dmid(&instance, 0u),
        2u,
        "as-call_indirect-mid(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export20_asX2DcallX5FindirectX2Dmid(&instance, 1u),
        2u,
        "as-call_indirect-mid(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export21_asX2DcallX5FindirectX2Dlast(&instance, 0u),
        2u,
        "as-call_indirect-last(0u)"
    );
    (void)(m4_ifX2E0Export14_asX2DstoreX2Dfirst(&instance, 0u));
    (void)(m4_ifX2E0Export14_asX2DstoreX2Dfirst(&instance, 1u));
    (void)(m4_ifX2E0Export13_asX2DstoreX2Dlast(&instance, 0u));
    (void)(m4_ifX2E0Export13_asX2DstoreX2Dlast(&instance, 1u));
    assertEqualU32(
        m4_ifX2E0Export20_asX2DmemoryX2EgrowX2Dvalue(&instance, 0u),
        1u,
        "as-memory.grow-value(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export20_asX2DmemoryX2EgrowX2Dvalue(&instance, 1u),
        1u,
        "as-memory.grow-value(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export13_asX2DcallX2Dvalue(&instance, 0u),
        0u,
        "as-call-value(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export13_asX2DcallX2Dvalue(&instance, 1u),
        1u,
        "as-call-value(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_asX2DreturnX2Dvalue(&instance, 0u),
        0u,
        "as-return-value(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_asX2DreturnX2Dvalue(&instance, 1u),
        1u,
        "as-return-value(1u)"
    );
    (void)(m4_ifX2E0Export15_asX2DdropX2Doperand(&instance, 0u));
    (void)(m4_ifX2E0Export15_asX2DdropX2Doperand(&instance, 1u));
    assertEqualU32(
        m4_ifX2E0Export11_asX2DbrX2Dvalue(&instance, 0u),
        0u,
        "as-br-value(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export11_asX2DbrX2Dvalue(&instance, 1u),
        1u,
        "as-br-value(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export18_asX2DlocalX2EsetX2Dvalue(&instance, 0u),
        0u,
        "as-local.set-value(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export18_asX2DlocalX2EsetX2Dvalue(&instance, 1u),
        1u,
        "as-local.set-value(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export18_asX2DlocalX2EteeX2Dvalue(&instance, 0u),
        0u,
        "as-local.tee-value(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export18_asX2DlocalX2EteeX2Dvalue(&instance, 1u),
        1u,
        "as-local.tee-value(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export19_asX2DglobalX2EsetX2Dvalue(&instance, 0u),
        0u,
        "as-global.set-value(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export19_asX2DglobalX2EsetX2Dvalue(&instance, 1u),
        1u,
        "as-global.set-value(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_asX2DloadX2Doperand(&instance, 0u),
        0u,
        "as-load-operand(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_asX2DloadX2Doperand(&instance, 1u),
        0u,
        "as-load-operand(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export16_asX2DunaryX2Doperand(&instance, 0u),
        0u,
        "as-unary-operand(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export16_asX2DunaryX2Doperand(&instance, 1u),
        0u,
        "as-unary-operand(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export16_asX2DunaryX2Doperand(&instance, 4294967295u),
        0u,
        "as-unary-operand(4294967295u)"
    );
    assertEqualU32(
        m4_ifX2E0Export17_asX2DbinaryX2Doperand(&instance, 0u, 0u),
        15u,
        "as-binary-operand(0u, 0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export17_asX2DbinaryX2Doperand(&instance, 0u, 1u),
        4294967284u,
        "as-binary-operand(0u, 1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export17_asX2DbinaryX2Doperand(&instance, 1u, 0u),
        4294967281u,
        "as-binary-operand(1u, 0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export17_asX2DbinaryX2Doperand(&instance, 1u, 1u),
        12u,
        "as-binary-operand(1u, 1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_asX2DtestX2Doperand(&instance, 0u),
        1u,
        "as-test-operand(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_asX2DtestX2Doperand(&instance, 1u),
        0u,
        "as-test-operand(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export18_asX2DcompareX2Doperand(&instance, 0u, 0u),
        1u,
        "as-compare-operand(0u, 0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export18_asX2DcompareX2Doperand(&instance, 0u, 1u),
        0u,
        "as-compare-operand(0u, 1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export18_asX2DcompareX2Doperand(&instance, 1u, 0u),
        1u,
        "as-compare-operand(1u, 0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export18_asX2DcompareX2Doperand(&instance, 1u, 1u),
        0u,
        "as-compare-operand(1u, 1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export18_asX2DbinaryX2Doperands(&instance, 0u),
        4294967284u,
        "as-binary-operands(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export18_asX2DbinaryX2Doperands(&instance, 1u),
        12u,
        "as-binary-operands(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export19_asX2DcompareX2Doperands(&instance, 0u),
        1u,
        "as-compare-operands(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export19_asX2DcompareX2Doperands(&instance, 1u),
        0u,
        "as-compare-operands(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export17_asX2DmixedX2Doperands(&instance, 0u),
        4294967293u,
        "as-mixed-operands(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export17_asX2DmixedX2Doperands(&instance, 1u),
        27u,
        "as-mixed-operands(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export10_breakX2Dbare(&instance),
        19u,
        "break-bare()"
    );
    assertEqualU32(
        m4_ifX2E0Export11_breakX2Dvalue(&instance, 1u),
        18u,
        "break-value(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export11_breakX2Dvalue(&instance, 0u),
        21u,
        "break-value(0u)"
    );
    {
        struct w2c2_result_iij result;
        result = m4_ifX2E0Export17_breakX2DmultiX2Dvalue(&instance, 0u);
        assertEqualU32(
            result.v0,
            4294967278u,
            "break-multi-value(0u) result 0"
        );
        assertEqualU32(
            result.v1,
            18u,
            "break-multi-value(0u) result 1"
        );
        assertEqualU64(
            result.v2,
            18446744073709551598ull,
            "break-multi-value(0u) result 2"
        );
    }
    {
        struct w2c2_result_iij result;
        result = m4_ifX2E0Export17_breakX2DmultiX2Dvalue(&instance, 1u);
        assertEqualU32(
            result.v0,
            18u,
            "break-multi-value(1u) result 0"
        );
        assertEqualU32(
            result.v1,
            4294967278u,
            "break-multi-value(1u) result 1"
        );
        assertEqualU64(
            result.v2,
            18ull,
            "break-multi-value(1u) result 2"
        );
    }
    assertEqualU32(
        m4_ifX2E0Export5_param(&instance, 0u),
        4294967295u,
        "param(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export5_param(&instance, 1u),
        3u,
        "param(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export6_params(&instance, 0u),
        4294967295u,
        "params(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export6_params(&instance, 1u),
        3u,
        "params(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export9_paramsX2Did(&instance, 0u),
        3u,
        "params-id(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export9_paramsX2Did(&instance, 1u),
        3u,
        "params-id(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export11_paramX2Dbreak(&instance, 0u),
        4294967295u,
        "param-break(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export11_paramX2Dbreak(&instance, 1u),
        3u,
        "param-break(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export12_paramsX2Dbreak(&instance, 0u),
        4294967295u,
        "params-break(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export12_paramsX2Dbreak(&instance, 1u),
        3u,
        "params-break(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_paramsX2DidX2Dbreak(&instance, 0u),
        3u,
        "params-id-break(0u)"
    );
    assertEqualU32(
        m4_ifX2E0Export15_paramsX2DidX2Dbreak(&instance, 1u),
        3u,
        "params-id-break(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export7_effects(&instance, 1u),
        4294967282u,
        "effects(1u)"
    );
    assertEqualU32(
        m4_ifX2E0Export7_effects(&instance, 0u),
        4294967290u,
        "effects(0u)"
    );
    {
        struct w2c2_result_ji result;
        result = m4_ifX2E0Export18_add64X5FuX5FwithX5Fcarry(&instance, 0ull, 0ull, 0u);
        assertEqualU64(
            result.v0,
            0ull,
            "add64_u_with_carry(0ull, 0ull, 0u) result 0"
        );
        assertEqualU32(
            result.v1,
            0u,
            "add64_u_with_carry(0ull, 0ull, 0u) result 1"
        );
    }
    {
        struct w2c2_result_ji result;
        result = m4_ifX2E0Export18_add64X5FuX5FwithX5Fcarry(&instance, 100ull, 124ull, 0u);
        assertEqualU64(
            result.v0,
            224ull,
            "add64_u_with_carry(100ull, 124ull, 0u) result 0"
        );
        assertEqualU32(
            result.v1,
            0u,
            "add64_u_with_carry(100ull, 124ull, 0u) result 1"
        );
    }
    {
        struct w2c2_result_ji result;
        result = m4_ifX2E0Export18_add64X5FuX5FwithX5Fcarry(&instance, 18446744073709551615ull, 0ull, 0u);
        assertEqualU64(
            result.v0,
            18446744073709551615ull,
            "add64_u_with_carry(18446744073709551615ull, 0ull, 0u) result 0"
        );
        assertEqualU32(
            result.v1,
            0u,
            "add64_u_with_carry(18446744073709551615ull, 0ull, 0u) result 1"
        );
    }
    {
        struct w2c2_result_ji result;
        result = m4_ifX2E0Export18_add64X5FuX5FwithX5Fcarry(&instance, 18446744073709551615ull, 1ull, 0u);
        assertEqualU64(
            result.v0,
            0ull,
            "add64_u_with_carry(18446744073709551615ull, 1ull, 0u) result 0"
        );
        assertEqualU32(
            result.v1,
            1u,
            "add64_u_with_carry(18446744073709551615ull, 1ull, 0u) result 1"
        );
    }
    {
        struct w2c2_result_ji result;
        result = m4_ifX2E0Export18_add64X5FuX5FwithX5Fcarry(&instance, 18446744073709551615ull, 18446744073709551615ull, 0u);
        assertEqualU64(
            result.v0,
            18446744073709551614ull,
            "add64_u_with_carry(18446744073709551615ull, 18446744073709551615ull, 0u) result 0"
        );
        assertEqualU32(
            result.v1,
            1u,
            "add64_u_with_carry(18446744073709551615ull, 18446744073709551615ull, 0u) result 1"
        );
    }
    {
        struct w2c2_result_ji result;
        result = m4_ifX2E0Export18_add64X5FuX5FwithX5Fcarry(&instance, 18446744073709551615ull, 0ull, 1u);
        assertEqualU64(
            result.v0,
            0ull,
            "add64_u_with_carry(18446744073709551615ull, 0ull, 1u) result 0"
        );
        assertEqualU32(
            result.v1,
            1u,
            "add64_u_with_carry(18446744073709551615ull, 0ull, 1u) result 1"
        );
    }
    {
        struct w2c2_result_ji result;
        result = m4_ifX2E0Export18_add64X5FuX5FwithX5Fcarry(&instance, 18446744073709551615ull, 1ull, 1u);
        assertEqualU64(
            result.v0,
            1ull,
            "add64_u_with_carry(18446744073709551615ull, 1ull, 1u) result 0"
        );
        assertEqualU32(
            result.v1,
            1u,
            "add64_u_with_carry(18446744073709551615ull, 1ull, 1u) result 1"
        );
    }
    {
        struct w2c2_result_ji result;
        result = m4_ifX2E0Export18_add64X5FuX5FwithX5Fcarry(&instance, 9223372036854775808ull, 9223372036854775808ull, 0u);
        assertEqualU64(
            result.v0,
            0ull,
            "add64_u_with_carry(9223372036854775808ull, 9223372036854775808ull, 0u) result 0"
        );
        assertEqualU32(
            result.v1,
            1u,
            "add64_u_with_carry(9223372036854775808ull, 9223372036854775808ull, 0u) result 1"
        );
    }
    assertEqualU64(
        m4_ifX2E0Export17_add64X5FuX5Fsaturated(&instance, 0ull, 0ull),
        0ull,
        "add64_u_saturated(0ull, 0ull)"
    );
    assertEqualU64(
        m4_ifX2E0Export17_add64X5FuX5Fsaturated(&instance, 1230ull, 23ull),
        1253ull,
        "add64_u_saturated(1230ull, 23ull)"
    );
    assertEqualU64(
        m4_ifX2E0Export17_add64X5FuX5Fsaturated(&instance, 18446744073709551615ull, 0ull),
        18446744073709551615ull,
        "add64_u_saturated(18446744073709551615ull, 0ull)"
    );
    assertEqualU64(
        m4_ifX2E0Export17_add64X5FuX5Fsaturated(&instance, 18446744073709551615ull, 1ull),
        18446744073709551615ull,
        "add64_u_saturated(18446744073709551615ull, 1ull)"
    );
    assertEqualU64(
        m4_ifX2E0Export17_add64X5FuX5Fsaturated(&instance, 18446744073709551615ull, 18446744073709551615ull),
        18446744073709551615ull,
        "add64_u_saturated(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        m4_ifX2E0Export17_add64X5FuX5Fsaturated(&instance, 9223372036854775808ull, 9223372036854775808ull),
        18446744073709551615ull,
        "add64_u_saturated(9223372036854775808ull, 9223372036854775808ull)"
    );
    (void)(m4_ifX2E0Export8_typeX2Duse(&instance));
    (void)(m4_ifX2E0Export18_atypicalX2Dcondition(&instance));
    m4_ifX2E0FreeInstance(&instance);
}
