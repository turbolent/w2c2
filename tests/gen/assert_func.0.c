
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func.0.h"

void test() {
    m6_funcX2E0Instance instance;
    m6_funcX2E0Instantiate(&instance, resolveTestImports);
    printStart("func.0.wasm");
    m6_funcX2E0Export10_typeX2DuseX2D1(&instance);
    assertEqualU32(
        m6_funcX2E0Export10_typeX2DuseX2D2(&instance),
        0u,
        "type-use-2()"
    );
    m6_funcX2E0Export10_typeX2DuseX2D3(&instance, 1u);
    assertEqualU32(
        m6_funcX2E0Export10_typeX2DuseX2D4(&instance, 1u, 1.0, 1u),
        0u,
        "type-use-4(1u, 1.0, 1u)"
    );
    assertEqualU32(
        m6_funcX2E0Export10_typeX2DuseX2D5(&instance),
        0u,
        "type-use-5()"
    );
    m6_funcX2E0Export10_typeX2DuseX2D6(&instance, 1u);
    assertEqualU32(
        m6_funcX2E0Export10_typeX2DuseX2D7(&instance, 1u, 1.0, 1u),
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
        i32_reinterpret_f32(m6_funcX2E0Export15_paramX2DfirstX2Df32(&instance, 2.0, 3.0)),
        1073741824u,
        "param-first-f32(2.0, 3.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export15_paramX2DfirstX2Df64(&instance, 2.0, 3.0)),
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
        i32_reinterpret_f32(m6_funcX2E0Export16_paramX2DsecondX2Df32(&instance, 2.0, 3.0)),
        1077936128u,
        "param-second-f32(2.0, 3.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export16_paramX2DsecondX2Df64(&instance, 2.0, 3.0)),
        4613937818241073152ull,
        "param-second-f64(2.0, 3.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m6_funcX2E0Export11_paramX2Dmixed(&instance, 1.0, 2u, 3ull, 4u, 5.5, 6u)),
        4617878467915022336ull,
        "param-mixed(1.0, 2u, 3ull, 4u, 5.5, 6u)"
    );
    m6_funcX2E0Export5_empty(&instance);
    m6_funcX2E0Export10_valueX2Dvoid(&instance);
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
    m6_funcX2E0Export16_valueX2DblockX2Dvoid(&instance);
    assertEqualU32(
        m6_funcX2E0Export15_valueX2DblockX2Di32(&instance),
        77u,
        "value-block-i32()"
    );
    m6_funcX2E0Export12_returnX2Dempty(&instance);
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
    assertEqualU32(
        m6_funcX2E0Export16_returnX2DblockX2Di32(&instance),
        77u,
        "return-block-i32()"
    );
    m6_funcX2E0Export11_breakX2Dempty(&instance);
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
    assertEqualU32(
        m6_funcX2E0Export15_breakX2DblockX2Di32(&instance),
        77u,
        "break-block-i32()"
    );
    m6_funcX2E0Export17_breakX2DbrX5FifX2Dempty(&instance, 0u);
    m6_funcX2E0Export17_breakX2DbrX5FifX2Dempty(&instance, 2u);
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
    m6_funcX2E0Export20_breakX2DbrX5FtableX2Dempty(&instance, 0u);
    m6_funcX2E0Export20_breakX2DbrX5FtableX2Dempty(&instance, 1u);
    m6_funcX2E0Export20_breakX2DbrX5FtableX2Dempty(&instance, 5u);
    m6_funcX2E0Export20_breakX2DbrX5FtableX2Dempty(&instance, 4294967295u);
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
    m6_funcX2E0Export27_breakX2DbrX5FtableX2DnestedX2Dempty(&instance, 0u);
    m6_funcX2E0Export27_breakX2DbrX5FtableX2DnestedX2Dempty(&instance, 1u);
    m6_funcX2E0Export27_breakX2DbrX5FtableX2DnestedX2Dempty(&instance, 3u);
    m6_funcX2E0Export27_breakX2DbrX5FtableX2DnestedX2Dempty(&instance, 4294967294u);
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
}
