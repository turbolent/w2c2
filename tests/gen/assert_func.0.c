
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func.0.h"

void test() {
    func0Instance instance;
    func0Instantiate(&instance, resolveTestImports);
    printStart("func.0.wasm");
    func0_typeX2DuseX2D1(&instance);
    assertEqualU32(
        func0_typeX2DuseX2D2(&instance),
        0u,
        "type-use-2()"
    );
    func0_typeX2DuseX2D3(&instance, 1u);
    assertEqualU32(
        func0_typeX2DuseX2D4(&instance, 1u, 1.0, 1u),
        0u,
        "type-use-4(1u, 1.0, 1u)"
    );
    assertEqualU32(
        func0_typeX2DuseX2D5(&instance),
        0u,
        "type-use-5()"
    );
    func0_typeX2DuseX2D6(&instance, 1u);
    assertEqualU32(
        func0_typeX2DuseX2D7(&instance, 1u, 1.0, 1u),
        0u,
        "type-use-7(1u, 1.0, 1u)"
    );
    assertEqualU32(
        func0_localX2DfirstX2Di32(&instance),
        0u,
        "local-first-i32()"
    );
    assertEqualU64(
        func0_localX2DfirstX2Di64(&instance),
        0ull,
        "local-first-i64()"
    );
    assertEqualF32(
        func0_localX2DfirstX2Df32(&instance),
        0.0,
        "local-first-f32()"
    );
    assertEqualF64(
        func0_localX2DfirstX2Df64(&instance),
        0.0,
        "local-first-f64()"
    );
    assertEqualU32(
        func0_localX2DsecondX2Di32(&instance),
        0u,
        "local-second-i32()"
    );
    assertEqualU64(
        func0_localX2DsecondX2Di64(&instance),
        0ull,
        "local-second-i64()"
    );
    assertEqualF32(
        func0_localX2DsecondX2Df32(&instance),
        0.0,
        "local-second-f32()"
    );
    assertEqualF64(
        func0_localX2DsecondX2Df64(&instance),
        0.0,
        "local-second-f64()"
    );
    assertEqualF64(
        func0_localX2Dmixed(&instance),
        0.0,
        "local-mixed()"
    );
    assertEqualU32(
        func0_paramX2DfirstX2Di32(&instance, 2u, 3u),
        2u,
        "param-first-i32(2u, 3u)"
    );
    assertEqualU64(
        func0_paramX2DfirstX2Di64(&instance, 2ull, 3ull),
        2ull,
        "param-first-i64(2ull, 3ull)"
    );
    assertEqualF32(
        func0_paramX2DfirstX2Df32(&instance, 2.0, 3.0),
        2.0,
        "param-first-f32(2.0, 3.0)"
    );
    assertEqualF64(
        func0_paramX2DfirstX2Df64(&instance, 2.0, 3.0),
        2.0,
        "param-first-f64(2.0, 3.0)"
    );
    assertEqualU32(
        func0_paramX2DsecondX2Di32(&instance, 2u, 3u),
        3u,
        "param-second-i32(2u, 3u)"
    );
    assertEqualU64(
        func0_paramX2DsecondX2Di64(&instance, 2ull, 3ull),
        3ull,
        "param-second-i64(2ull, 3ull)"
    );
    assertEqualF32(
        func0_paramX2DsecondX2Df32(&instance, 2.0, 3.0),
        3.0,
        "param-second-f32(2.0, 3.0)"
    );
    assertEqualF64(
        func0_paramX2DsecondX2Df64(&instance, 2.0, 3.0),
        3.0,
        "param-second-f64(2.0, 3.0)"
    );
    assertEqualF64(
        func0_paramX2Dmixed(&instance, 1.0, 2u, 3ull, 4u, 5.5, 6u),
        5.5,
        "param-mixed(1.0, 2u, 3ull, 4u, 5.5, 6u)"
    );
    func0_empty(&instance);
    func0_valueX2Dvoid(&instance);
    assertEqualU32(
        func0_valueX2Di32(&instance),
        77u,
        "value-i32()"
    );
    assertEqualU64(
        func0_valueX2Di64(&instance),
        7777ull,
        "value-i64()"
    );
    assertEqualF32(
        func0_valueX2Df32(&instance),
        77.69999694824219,
        "value-f32()"
    );
    assertEqualF64(
        func0_valueX2Df64(&instance),
        77.77,
        "value-f64()"
    );
    func0_valueX2DblockX2Dvoid(&instance);
    assertEqualU32(
        func0_valueX2DblockX2Di32(&instance),
        77u,
        "value-block-i32()"
    );
    func0_returnX2Dempty(&instance);
    assertEqualU32(
        func0_returnX2Di32(&instance),
        78u,
        "return-i32()"
    );
    assertEqualU64(
        func0_returnX2Di64(&instance),
        7878ull,
        "return-i64()"
    );
    assertEqualF32(
        func0_returnX2Df32(&instance),
        78.69999694824219,
        "return-f32()"
    );
    assertEqualF64(
        func0_returnX2Df64(&instance),
        78.78,
        "return-f64()"
    );
    assertEqualU32(
        func0_returnX2DblockX2Di32(&instance),
        77u,
        "return-block-i32()"
    );
    func0_breakX2Dempty(&instance);
    assertEqualU32(
        func0_breakX2Di32(&instance),
        79u,
        "break-i32()"
    );
    assertEqualU64(
        func0_breakX2Di64(&instance),
        7979ull,
        "break-i64()"
    );
    assertEqualF32(
        func0_breakX2Df32(&instance),
        79.9000015258789,
        "break-f32()"
    );
    assertEqualF64(
        func0_breakX2Df64(&instance),
        79.79,
        "break-f64()"
    );
    assertEqualU32(
        func0_breakX2DblockX2Di32(&instance),
        77u,
        "break-block-i32()"
    );
    func0_breakX2Dbr_ifX2Dempty(&instance, 0u);
    func0_breakX2Dbr_ifX2Dempty(&instance, 2u);
    assertEqualU32(
        func0_breakX2Dbr_ifX2Dnum(&instance, 0u),
        51u,
        "break-br_if-num(0u)"
    );
    assertEqualU32(
        func0_breakX2Dbr_ifX2Dnum(&instance, 1u),
        50u,
        "break-br_if-num(1u)"
    );
    func0_breakX2Dbr_tableX2Dempty(&instance, 0u);
    func0_breakX2Dbr_tableX2Dempty(&instance, 1u);
    func0_breakX2Dbr_tableX2Dempty(&instance, 5u);
    func0_breakX2Dbr_tableX2Dempty(&instance, 4294967295u);
    assertEqualU32(
        func0_breakX2Dbr_tableX2Dnum(&instance, 0u),
        50u,
        "break-br_table-num(0u)"
    );
    assertEqualU32(
        func0_breakX2Dbr_tableX2Dnum(&instance, 1u),
        50u,
        "break-br_table-num(1u)"
    );
    assertEqualU32(
        func0_breakX2Dbr_tableX2Dnum(&instance, 10u),
        50u,
        "break-br_table-num(10u)"
    );
    assertEqualU32(
        func0_breakX2Dbr_tableX2Dnum(&instance, 4294967196u),
        50u,
        "break-br_table-num(4294967196u)"
    );
    func0_breakX2Dbr_tableX2DnestedX2Dempty(&instance, 0u);
    func0_breakX2Dbr_tableX2DnestedX2Dempty(&instance, 1u);
    func0_breakX2Dbr_tableX2DnestedX2Dempty(&instance, 3u);
    func0_breakX2Dbr_tableX2DnestedX2Dempty(&instance, 4294967294u);
    assertEqualU32(
        func0_breakX2Dbr_tableX2DnestedX2Dnum(&instance, 0u),
        52u,
        "break-br_table-nested-num(0u)"
    );
    assertEqualU32(
        func0_breakX2Dbr_tableX2DnestedX2Dnum(&instance, 1u),
        50u,
        "break-br_table-nested-num(1u)"
    );
    assertEqualU32(
        func0_breakX2Dbr_tableX2DnestedX2Dnum(&instance, 2u),
        52u,
        "break-br_table-nested-num(2u)"
    );
    assertEqualU32(
        func0_breakX2Dbr_tableX2DnestedX2Dnum(&instance, 4294967293u),
        52u,
        "break-br_table-nested-num(4294967293u)"
    );
    assertEqualU32(
        func0_initX2DlocalX2Di32(&instance),
        0u,
        "init-local-i32()"
    );
    assertEqualU64(
        func0_initX2DlocalX2Di64(&instance),
        0ull,
        "init-local-i64()"
    );
    assertEqualF32(
        func0_initX2DlocalX2Df32(&instance),
        0.0,
        "init-local-f32()"
    );
    assertEqualF64(
        func0_initX2DlocalX2Df64(&instance),
        0.0,
        "init-local-f64()"
    );
}
