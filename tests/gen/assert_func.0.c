#include "test.h"
#include "test_func.0.h"

void test(void) {
    static m6_funcX2E0Instance instance;
    m6_funcX2E0Instantiate(&instance, resolveTestImports);
    printStart("func.0.wasm");
    (void)(m6_funcX2E0Export10_typeX2DuseX2D1(&instance));
    assertEqualU32(
        m6_funcX2E0Export10_typeX2DuseX2D2(&instance),
        0u,
        "type-use-2()"
    );
    (void)(m6_funcX2E0Export10_typeX2DuseX2D3(&instance, 1u));
    assertEqualU32(
        m6_funcX2E0Export10_typeX2DuseX2D4(&instance, 1u, f64_reinterpret_i64(0x3ff0000000000000ull), 1u),
        0u,
        "type-use-4(1u, 1.0, 1u)"
    );
    assertEqualU32(
        m6_funcX2E0Export10_typeX2DuseX2D5(&instance),
        0u,
        "type-use-5()"
    );
    (void)(m6_funcX2E0Export10_typeX2DuseX2D6(&instance, 1u));
    assertEqualU32(
        m6_funcX2E0Export10_typeX2DuseX2D7(&instance, 1u, f64_reinterpret_i64(0x3ff0000000000000ull), 1u),
        0u,
        "type-use-7(1u, 1.0, 1u)"
    );
    assertEqualU32(
        m6_funcX2E0Export15_localX2DfirstX2Di32(&instance),
        0u,
        "local-first-i32()"
    );
    assertEqualU64(
        m6_funcX2E0Export15_localX2DfirstX2Di64(&instance),
        0ull,
        "local-first-i64()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_funcX2E0Export15_localX2DfirstX2Df32(&instance)),
        0u,
        "local-first-f32()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export15_localX2DfirstX2Df64(&instance)),
        0ull,
        "local-first-f64()"
    );
    assertEqualU32(
        m6_funcX2E0Export16_localX2DsecondX2Di32(&instance),
        0u,
        "local-second-i32()"
    );
    assertEqualU64(
        m6_funcX2E0Export16_localX2DsecondX2Di64(&instance),
        0ull,
        "local-second-i64()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_funcX2E0Export16_localX2DsecondX2Df32(&instance)),
        0u,
        "local-second-f32()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export16_localX2DsecondX2Df64(&instance)),
        0ull,
        "local-second-f64()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export11_localX2Dmixed(&instance)),
        0ull,
        "local-mixed()"
    );
    assertEqualU32(
        m6_funcX2E0Export15_paramX2DfirstX2Di32(&instance, 2u, 3u),
        2u,
        "param-first-i32(2u, 3u)"
    );
    assertEqualU64(
        m6_funcX2E0Export15_paramX2DfirstX2Di64(&instance, 2ull, 3ull),
        2ull,
        "param-first-i64(2ull, 3ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_funcX2E0Export15_paramX2DfirstX2Df32(&instance, f32_reinterpret_i32(0x40000000u), f32_reinterpret_i32(0x40400000u))),
        1073741824u,
        "param-first-f32(2.0, 3.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export15_paramX2DfirstX2Df64(&instance, f64_reinterpret_i64(0x4000000000000000ull), f64_reinterpret_i64(0x4008000000000000ull))),
        4611686018427387904ull,
        "param-first-f64(2.0, 3.0)"
    );
    assertEqualU32(
        m6_funcX2E0Export16_paramX2DsecondX2Di32(&instance, 2u, 3u),
        3u,
        "param-second-i32(2u, 3u)"
    );
    assertEqualU64(
        m6_funcX2E0Export16_paramX2DsecondX2Di64(&instance, 2ull, 3ull),
        3ull,
        "param-second-i64(2ull, 3ull)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_funcX2E0Export16_paramX2DsecondX2Df32(&instance, f32_reinterpret_i32(0x40000000u), f32_reinterpret_i32(0x40400000u))),
        1077936128u,
        "param-second-f32(2.0, 3.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export16_paramX2DsecondX2Df64(&instance, f64_reinterpret_i64(0x4000000000000000ull), f64_reinterpret_i64(0x4008000000000000ull))),
        4613937818241073152ull,
        "param-second-f64(2.0, 3.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export11_paramX2Dmixed(&instance, f32_reinterpret_i32(0x3f800000u), 2u, 3ull, 4u, f64_reinterpret_i64(0x4016000000000000ull), 6u)),
        4617878467915022336ull,
        "param-mixed(1.0, 2u, 3ull, 4u, 5.5, 6u)"
    );
    (void)(m6_funcX2E0Export5_empty(&instance));
    (void)(m6_funcX2E0Export10_valueX2Dvoid(&instance));
    assertEqualU32(
        m6_funcX2E0Export9_valueX2Di32(&instance),
        77u,
        "value-i32()"
    );
    assertEqualU64(
        m6_funcX2E0Export9_valueX2Di64(&instance),
        7777ull,
        "value-i64()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_funcX2E0Export9_valueX2Df32(&instance)),
        1117480550u,
        "value-f32()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export9_valueX2Df64(&instance)),
        4635172994171566817ull,
        "value-f64()"
    );
    {
        struct w2c2_result_id result;
        result = m6_funcX2E0Export13_valueX2Di32X2Df64(&instance);
        assertEqualU32(
            result.v0,
            77u,
            "value-i32-f64() result 0"
        );
        assertEqualU64(
            i64_reinterpret_f64(result.v1),
            4619567317775286272ull,
            "value-i32-f64() result 1"
        );
    }
    {
        struct w2c2_result_iii result;
        result = m6_funcX2E0Export17_valueX2Di32X2Di32X2Di32(&instance);
        assertEqualU32(
            result.v0,
            1u,
            "value-i32-i32-i32() result 0"
        );
        assertEqualU32(
            result.v1,
            2u,
            "value-i32-i32-i32() result 1"
        );
        assertEqualU32(
            result.v2,
            3u,
            "value-i32-i32-i32() result 2"
        );
    }
    (void)(m6_funcX2E0Export16_valueX2DblockX2Dvoid(&instance));
    assertEqualU32(
        m6_funcX2E0Export15_valueX2DblockX2Di32(&instance),
        77u,
        "value-block-i32()"
    );
    {
        struct w2c2_result_ij result;
        result = m6_funcX2E0Export19_valueX2DblockX2Di32X2Di64(&instance);
        assertEqualU32(
            result.v0,
            1u,
            "value-block-i32-i64() result 0"
        );
        assertEqualU64(
            result.v1,
            2ull,
            "value-block-i32-i64() result 1"
        );
    }
    (void)(m6_funcX2E0Export12_returnX2Dempty(&instance));
    assertEqualU32(
        m6_funcX2E0Export10_returnX2Di32(&instance),
        78u,
        "return-i32()"
    );
    assertEqualU64(
        m6_funcX2E0Export10_returnX2Di64(&instance),
        7878ull,
        "return-i64()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_funcX2E0Export10_returnX2Df32(&instance)),
        1117611622u,
        "return-f32()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export10_returnX2Df64(&instance)),
        4635244066603186258ull,
        "return-f64()"
    );
    {
        struct w2c2_result_id result;
        result = m6_funcX2E0Export14_returnX2Di32X2Df64(&instance);
        assertEqualU32(
            result.v0,
            78u,
            "return-i32-f64() result 0"
        );
        assertEqualU64(
            i64_reinterpret_f64(result.v1),
            4635244066603186258ull,
            "return-i32-f64() result 1"
        );
    }
    {
        struct w2c2_result_iii result;
        result = m6_funcX2E0Export18_returnX2Di32X2Di32X2Di32(&instance);
        assertEqualU32(
            result.v0,
            1u,
            "return-i32-i32-i32() result 0"
        );
        assertEqualU32(
            result.v1,
            2u,
            "return-i32-i32-i32() result 1"
        );
        assertEqualU32(
            result.v2,
            3u,
            "return-i32-i32-i32() result 2"
        );
    }
    assertEqualU32(
        m6_funcX2E0Export16_returnX2DblockX2Di32(&instance),
        77u,
        "return-block-i32()"
    );
    {
        struct w2c2_result_ij result;
        result = m6_funcX2E0Export20_returnX2DblockX2Di32X2Di64(&instance);
        assertEqualU32(
            result.v0,
            1u,
            "return-block-i32-i64() result 0"
        );
        assertEqualU64(
            result.v1,
            2ull,
            "return-block-i32-i64() result 1"
        );
    }
    (void)(m6_funcX2E0Export11_breakX2Dempty(&instance));
    assertEqualU32(
        m6_funcX2E0Export9_breakX2Di32(&instance),
        79u,
        "break-i32()"
    );
    assertEqualU64(
        m6_funcX2E0Export9_breakX2Di64(&instance),
        7979ull,
        "break-i64()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_funcX2E0Export9_breakX2Df32(&instance)),
        1117768909u,
        "break-f32()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export9_breakX2Df64(&instance)),
        4635315139034805699ull,
        "break-f64()"
    );
    {
        struct w2c2_result_id result;
        result = m6_funcX2E0Export13_breakX2Di32X2Df64(&instance);
        assertEqualU32(
            result.v0,
            79u,
            "break-i32-f64() result 0"
        );
        assertEqualU64(
            i64_reinterpret_f64(result.v1),
            4635315139034805699ull,
            "break-i32-f64() result 1"
        );
    }
    {
        struct w2c2_result_iii result;
        result = m6_funcX2E0Export17_breakX2Di32X2Di32X2Di32(&instance);
        assertEqualU32(
            result.v0,
            1u,
            "break-i32-i32-i32() result 0"
        );
        assertEqualU32(
            result.v1,
            2u,
            "break-i32-i32-i32() result 1"
        );
        assertEqualU32(
            result.v2,
            3u,
            "break-i32-i32-i32() result 2"
        );
    }
    assertEqualU32(
        m6_funcX2E0Export15_breakX2DblockX2Di32(&instance),
        77u,
        "break-block-i32()"
    );
    {
        struct w2c2_result_ij result;
        result = m6_funcX2E0Export19_breakX2DblockX2Di32X2Di64(&instance);
        assertEqualU32(
            result.v0,
            1u,
            "break-block-i32-i64() result 0"
        );
        assertEqualU64(
            result.v1,
            2ull,
            "break-block-i32-i64() result 1"
        );
    }
    (void)(m6_funcX2E0Export17_breakX2DbrX5FifX2Dempty(&instance, 0u));
    (void)(m6_funcX2E0Export17_breakX2DbrX5FifX2Dempty(&instance, 2u));
    assertEqualU32(
        m6_funcX2E0Export15_breakX2DbrX5FifX2Dnum(&instance, 0u),
        51u,
        "break-br_if-num(0u)"
    );
    assertEqualU32(
        m6_funcX2E0Export15_breakX2DbrX5FifX2Dnum(&instance, 1u),
        50u,
        "break-br_if-num(1u)"
    );
    {
        struct w2c2_result_ij result;
        result = m6_funcX2E0Export19_breakX2DbrX5FifX2DnumX2Dnum(&instance, 0u);
        assertEqualU32(
            result.v0,
            51u,
            "break-br_if-num-num(0u) result 0"
        );
        assertEqualU64(
            result.v1,
            52ull,
            "break-br_if-num-num(0u) result 1"
        );
    }
    {
        struct w2c2_result_ij result;
        result = m6_funcX2E0Export19_breakX2DbrX5FifX2DnumX2Dnum(&instance, 1u);
        assertEqualU32(
            result.v0,
            50u,
            "break-br_if-num-num(1u) result 0"
        );
        assertEqualU64(
            result.v1,
            51ull,
            "break-br_if-num-num(1u) result 1"
        );
    }
    (void)(m6_funcX2E0Export20_breakX2DbrX5FtableX2Dempty(&instance, 0u));
    (void)(m6_funcX2E0Export20_breakX2DbrX5FtableX2Dempty(&instance, 1u));
    (void)(m6_funcX2E0Export20_breakX2DbrX5FtableX2Dempty(&instance, 5u));
    (void)(m6_funcX2E0Export20_breakX2DbrX5FtableX2Dempty(&instance, 4294967295u));
    assertEqualU32(
        m6_funcX2E0Export18_breakX2DbrX5FtableX2Dnum(&instance, 0u),
        50u,
        "break-br_table-num(0u)"
    );
    assertEqualU32(
        m6_funcX2E0Export18_breakX2DbrX5FtableX2Dnum(&instance, 1u),
        50u,
        "break-br_table-num(1u)"
    );
    assertEqualU32(
        m6_funcX2E0Export18_breakX2DbrX5FtableX2Dnum(&instance, 10u),
        50u,
        "break-br_table-num(10u)"
    );
    assertEqualU32(
        m6_funcX2E0Export18_breakX2DbrX5FtableX2Dnum(&instance, 4294967196u),
        50u,
        "break-br_table-num(4294967196u)"
    );
    {
        struct w2c2_result_ij result;
        result = m6_funcX2E0Export22_breakX2DbrX5FtableX2DnumX2Dnum(&instance, 0u);
        assertEqualU32(
            result.v0,
            50u,
            "break-br_table-num-num(0u) result 0"
        );
        assertEqualU64(
            result.v1,
            51ull,
            "break-br_table-num-num(0u) result 1"
        );
    }
    {
        struct w2c2_result_ij result;
        result = m6_funcX2E0Export22_breakX2DbrX5FtableX2DnumX2Dnum(&instance, 1u);
        assertEqualU32(
            result.v0,
            50u,
            "break-br_table-num-num(1u) result 0"
        );
        assertEqualU64(
            result.v1,
            51ull,
            "break-br_table-num-num(1u) result 1"
        );
    }
    {
        struct w2c2_result_ij result;
        result = m6_funcX2E0Export22_breakX2DbrX5FtableX2DnumX2Dnum(&instance, 10u);
        assertEqualU32(
            result.v0,
            50u,
            "break-br_table-num-num(10u) result 0"
        );
        assertEqualU64(
            result.v1,
            51ull,
            "break-br_table-num-num(10u) result 1"
        );
    }
    {
        struct w2c2_result_ij result;
        result = m6_funcX2E0Export22_breakX2DbrX5FtableX2DnumX2Dnum(&instance, 4294967196u);
        assertEqualU32(
            result.v0,
            50u,
            "break-br_table-num-num(4294967196u) result 0"
        );
        assertEqualU64(
            result.v1,
            51ull,
            "break-br_table-num-num(4294967196u) result 1"
        );
    }
    (void)(m6_funcX2E0Export27_breakX2DbrX5FtableX2DnestedX2Dempty(&instance, 0u));
    (void)(m6_funcX2E0Export27_breakX2DbrX5FtableX2DnestedX2Dempty(&instance, 1u));
    (void)(m6_funcX2E0Export27_breakX2DbrX5FtableX2DnestedX2Dempty(&instance, 3u));
    (void)(m6_funcX2E0Export27_breakX2DbrX5FtableX2DnestedX2Dempty(&instance, 4294967294u));
    assertEqualU32(
        m6_funcX2E0Export25_breakX2DbrX5FtableX2DnestedX2Dnum(&instance, 0u),
        52u,
        "break-br_table-nested-num(0u)"
    );
    assertEqualU32(
        m6_funcX2E0Export25_breakX2DbrX5FtableX2DnestedX2Dnum(&instance, 1u),
        50u,
        "break-br_table-nested-num(1u)"
    );
    assertEqualU32(
        m6_funcX2E0Export25_breakX2DbrX5FtableX2DnestedX2Dnum(&instance, 2u),
        52u,
        "break-br_table-nested-num(2u)"
    );
    assertEqualU32(
        m6_funcX2E0Export25_breakX2DbrX5FtableX2DnestedX2Dnum(&instance, 4294967293u),
        52u,
        "break-br_table-nested-num(4294967293u)"
    );
    {
        struct w2c2_result_ii result;
        result = m6_funcX2E0Export29_breakX2DbrX5FtableX2DnestedX2DnumX2Dnum(&instance, 0u);
        assertEqualU32(
            result.v0,
            101u,
            "break-br_table-nested-num-num(0u) result 0"
        );
        assertEqualU32(
            result.v1,
            52u,
            "break-br_table-nested-num-num(0u) result 1"
        );
    }
    {
        struct w2c2_result_ii result;
        result = m6_funcX2E0Export29_breakX2DbrX5FtableX2DnestedX2DnumX2Dnum(&instance, 1u);
        assertEqualU32(
            result.v0,
            50u,
            "break-br_table-nested-num-num(1u) result 0"
        );
        assertEqualU32(
            result.v1,
            51u,
            "break-br_table-nested-num-num(1u) result 1"
        );
    }
    {
        struct w2c2_result_ii result;
        result = m6_funcX2E0Export29_breakX2DbrX5FtableX2DnestedX2DnumX2Dnum(&instance, 2u);
        assertEqualU32(
            result.v0,
            101u,
            "break-br_table-nested-num-num(2u) result 0"
        );
        assertEqualU32(
            result.v1,
            52u,
            "break-br_table-nested-num-num(2u) result 1"
        );
    }
    {
        struct w2c2_result_ii result;
        result = m6_funcX2E0Export29_breakX2DbrX5FtableX2DnestedX2DnumX2Dnum(&instance, 4294967293u);
        assertEqualU32(
            result.v0,
            101u,
            "break-br_table-nested-num-num(4294967293u) result 0"
        );
        assertEqualU32(
            result.v1,
            52u,
            "break-br_table-nested-num-num(4294967293u) result 1"
        );
    }
    {
        struct w2c2_result_dfiiijfiifddifid result;
        result = m6_funcX2E0Export9_largeX2Dsig(&instance, 0u, 1ull, f32_reinterpret_i32(0x40000000u), f32_reinterpret_i32(0x40400000u), 4u, f64_reinterpret_i64(0x4014000000000000ull), f32_reinterpret_i32(0x40c00000u), 7u, 8u, 9u, f32_reinterpret_i32(0x41200000u), f64_reinterpret_i64(0x4026000000000000ull), f64_reinterpret_i64(0x4028000000000000ull), f64_reinterpret_i64(0x402a000000000000ull), 14u, 15u, f32_reinterpret_i32(0x41800000u));
        assertEqualU64(
            i64_reinterpret_f64(result.v0),
            4617315517961601024ull,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 0"
        );
        assertEqualU32(
            i32_reinterpret_f32(result.v1),
            1073741824u,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 1"
        );
        assertEqualU32(
            result.v2,
            0u,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 2"
        );
        assertEqualU32(
            result.v3,
            8u,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 3"
        );
        assertEqualU32(
            result.v4,
            7u,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 4"
        );
        assertEqualU64(
            result.v5,
            1ull,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 5"
        );
        assertEqualU32(
            i32_reinterpret_f32(result.v6),
            1077936128u,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 6"
        );
        assertEqualU32(
            result.v7,
            9u,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 7"
        );
        assertEqualU32(
            result.v8,
            4u,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 8"
        );
        assertEqualU32(
            i32_reinterpret_f32(result.v9),
            1086324736u,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 9"
        );
        assertEqualU64(
            i64_reinterpret_f64(result.v10),
            4623507967449235456ull,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 10"
        );
        assertEqualU64(
            i64_reinterpret_f64(result.v11),
            4622382067542392832ull,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 11"
        );
        assertEqualU32(
            result.v12,
            15u,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 12"
        );
        assertEqualU32(
            i32_reinterpret_f32(result.v13),
            1098907648u,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 13"
        );
        assertEqualU32(
            result.v14,
            14u,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 14"
        );
        assertEqualU64(
            i64_reinterpret_f64(result.v15),
            4622945017495814144ull,
            "large-sig(0u, 1ull, 2.0, 3.0, 4u, 5.0, 6.0, 7u, 8u, 9u, 10.0, 11.0, 12.0, 13.0, 14u, 15u, 16.0) result 15"
        );
    }
    assertEqualU32(
        m6_funcX2E0Export14_initX2DlocalX2Di32(&instance),
        0u,
        "init-local-i32()"
    );
    assertEqualU64(
        m6_funcX2E0Export14_initX2DlocalX2Di64(&instance),
        0ull,
        "init-local-i64()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m6_funcX2E0Export14_initX2DlocalX2Df32(&instance)),
        0u,
        "init-local-f32()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export14_initX2DlocalX2Df64(&instance)),
        0ull,
        "init-local-f64()"
    );
    m6_funcX2E0FreeInstance(&instance);
}
