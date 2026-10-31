#include "test.h"
#include "test_global.0.h"
#include "test_global.3.h"
#include "test_global.4.h"
#include "test_global.18.h"
#include "test_global.19.h"
#include "test_global.23.h"
#include "test_global.26.h"
#include "test_global.49.h"
#include "test_global.50.h"

static m8_globalX2E0Instance instance_0;
static m8_globalX2E3Instance instance_1;
static m8_globalX2E4Instance instance_2;
static m9_globalX2E18Instance instance_3;
static m9_globalX2E19Instance instance_4;
static m9_globalX2E23Instance instance_5;
static m9_globalX2E26Instance instance_6;
static m9_globalX2E49Instance instance_7;
static m9_globalX2E50Instance instance_8;

void test(void) {
    m8_globalX2E0Instantiate(&instance_0, resolveTestImports);
    printStart("global.0.wasm");
    assertEqualU32(
        m8_globalX2E0Export5_getX2Da(&instance_0),
        4294967294u,
        "WAST line 204: get-a()"
    );
    assertEqualU64(
        m8_globalX2E0Export5_getX2Db(&instance_0),
        18446744073709551611ull,
        "WAST line 205: get-b()"
    );
    assertEqualU32((m8_globalX2E0Export5_getX2Dr(&instance_0)) == wasmNullExternRef, 1u, "WAST line 206: get-r()");
    assertEqualU32((m8_globalX2E0Export6_getX2Dmr(&instance_0)) == wasmNullExternRef, 1u, "WAST line 207: get-mr()");
    assertEqualU32(
        m8_globalX2E0Export5_getX2Dx(&instance_0),
        4294967284u,
        "WAST line 208: get-x()"
    );
    assertEqualU64(
        m8_globalX2E0Export5_getX2Dy(&instance_0),
        18446744073709551601ull,
        "WAST line 209: get-y()"
    );
    assertEqualU32(
        m8_globalX2E0Export6_getX2Dz1(&instance_0),
        666u,
        "WAST line 210: get-z1()"
    );
    assertEqualU64(
        m8_globalX2E0Export6_getX2Dz2(&instance_0),
        666ull,
        "WAST line 211: get-z2()"
    );
    assertEqualU32(
        m8_globalX2E0Export6_getX2Dz3(&instance_0),
        42u,
        "WAST line 212: get-z3()"
    );
    assertEqualU64(
        m8_globalX2E0Export6_getX2Dz4(&instance_0),
        43ull,
        "WAST line 213: get-z4()"
    );
    assertEqualU32(
        m8_globalX2E0Export6_getX2Dz5(&instance_0),
        708u,
        "WAST line 214: get-z5()"
    );
    assertEqualU64(
        m8_globalX2E0Export6_getX2Dz6(&instance_0),
        708ull,
        "WAST line 215: get-z6()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_globalX2E0Export5_getX2D3(&instance_0)),
        3225419776u,
        "WAST line 217: get-3()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_globalX2E0Export5_getX2D4(&instance_0)),
        13839561654909534208ull,
        "WAST line 218: get-4()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_globalX2E0Export5_getX2D7(&instance_0)),
        3243245568u,
        "WAST line 219: get-7()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_globalX2E0Export5_getX2D8(&instance_0)),
        13847442954257432576ull,
        "WAST line 220: get-8()"
    );
    (void)(m8_globalX2E0Export5_setX2Dx(&instance_0, 6u));
    printOK("WAST line 222: set-x(6u)");
    (void)(m8_globalX2E0Export5_setX2Dy(&instance_0, 7ull));
    printOK("WAST line 223: set-y(7ull)");
    (void)(m8_globalX2E0Export5_setX2D7(&instance_0, f32_reinterpret_i32(0x41000000u)));
    printOK("WAST line 225: set-7(f32_reinterpret_i32(0x41000000u))");
    (void)(m8_globalX2E0Export5_setX2D8(&instance_0, f64_reinterpret_i64(0x4022000000000000ull)));
    printOK("WAST line 226: set-8(f64_reinterpret_i64(0x4022000000000000ull))");
    assertEqualU32(
        m8_globalX2E0Export5_getX2Dx(&instance_0),
        6u,
        "WAST line 228: get-x()"
    );
    assertEqualU64(
        m8_globalX2E0Export5_getX2Dy(&instance_0),
        7ull,
        "WAST line 229: get-y()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_globalX2E0Export5_getX2D7(&instance_0)),
        1090519040u,
        "WAST line 230: get-7()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_globalX2E0Export5_getX2D8(&instance_0)),
        4621256167635550208ull,
        "WAST line 231: get-8()"
    );
    (void)(m8_globalX2E0Export5_setX2D7(&instance_0, f32_reinterpret_i32(0x41000000u)));
    printOK("WAST line 233: set-7(f32_reinterpret_i32(0x41000000u))");
    (void)(m8_globalX2E0Export5_setX2D8(&instance_0, f64_reinterpret_i64(0x4022000000000000ull)));
    printOK("WAST line 234: set-8(f64_reinterpret_i64(0x4022000000000000ull))");
    (void)(m8_globalX2E0Export6_setX2Dmr(&instance_0, testExternRef(10u)));
    printOK("WAST line 235: set-mr(testExternRef(10u))");
    assertEqualU32(
        m8_globalX2E0Export5_getX2Dx(&instance_0),
        6u,
        "WAST line 237: get-x()"
    );
    assertEqualU64(
        m8_globalX2E0Export5_getX2Dy(&instance_0),
        7ull,
        "WAST line 238: get-y()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_globalX2E0Export5_getX2D7(&instance_0)),
        1090519040u,
        "WAST line 239: get-7()"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_globalX2E0Export5_getX2D8(&instance_0)),
        4621256167635550208ull,
        "WAST line 240: get-8()"
    );
    assertEqualU32((m8_globalX2E0Export6_getX2Dmr(&instance_0)) == testExternRef(10u), 1u, "WAST line 241: get-mr()");
    assertEqualU32(
        m8_globalX2E0Export15_asX2DselectX2Dfirst(&instance_0),
        6u,
        "WAST line 243: as-select-first()"
    );
    assertEqualU32(
        m8_globalX2E0Export13_asX2DselectX2Dmid(&instance_0),
        2u,
        "WAST line 244: as-select-mid()"
    );
    assertEqualU32(
        m8_globalX2E0Export14_asX2DselectX2Dlast(&instance_0),
        2u,
        "WAST line 245: as-select-last()"
    );
    assertEqualU32(
        m8_globalX2E0Export13_asX2DloopX2Dfirst(&instance_0),
        6u,
        "WAST line 247: as-loop-first()"
    );
    assertEqualU32(
        m8_globalX2E0Export11_asX2DloopX2Dmid(&instance_0),
        6u,
        "WAST line 248: as-loop-mid()"
    );
    assertEqualU32(
        m8_globalX2E0Export12_asX2DloopX2Dlast(&instance_0),
        6u,
        "WAST line 249: as-loop-last()"
    );
    assertEqualU32(
        m8_globalX2E0Export15_asX2DifX2Dcondition(&instance_0),
        2u,
        "WAST line 251: as-if-condition()"
    );
    assertEqualU32(
        m8_globalX2E0Export10_asX2DifX2Dthen(&instance_0),
        6u,
        "WAST line 252: as-if-then()"
    );
    assertEqualU32(
        m8_globalX2E0Export10_asX2DifX2Delse(&instance_0),
        6u,
        "WAST line 253: as-if-else()"
    );
    assertEqualU32(
        m8_globalX2E0Export14_asX2DbrX5FifX2Dfirst(&instance_0),
        6u,
        "WAST line 255: as-br_if-first()"
    );
    assertEqualU32(
        m8_globalX2E0Export13_asX2DbrX5FifX2Dlast(&instance_0),
        2u,
        "WAST line 256: as-br_if-last()"
    );
    assertEqualU32(
        m8_globalX2E0Export17_asX2DbrX5FtableX2Dfirst(&instance_0),
        6u,
        "WAST line 258: as-br_table-first()"
    );
    assertEqualU32(
        m8_globalX2E0Export16_asX2DbrX5FtableX2Dlast(&instance_0),
        2u,
        "WAST line 259: as-br_table-last()"
    );
    assertEqualU32(
        m8_globalX2E0Export22_asX2DcallX5FindirectX2Dfirst(&instance_0),
        6u,
        "WAST line 261: as-call_indirect-first()"
    );
    assertEqualU32(
        m8_globalX2E0Export20_asX2DcallX5FindirectX2Dmid(&instance_0),
        2u,
        "WAST line 262: as-call_indirect-mid()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m8_globalX2E0Export21_asX2DcallX5FindirectX2Dlast(&instance_0), "WAST line 263: as-call_indirect-last()");
#endif
    (void)(m8_globalX2E0Export14_asX2DstoreX2Dfirst(&instance_0));
    printOK("WAST line 265: as-store-first()");
    (void)(m8_globalX2E0Export13_asX2DstoreX2Dlast(&instance_0));
    printOK("WAST line 266: as-store-last()");
    assertEqualU32(
        m8_globalX2E0Export15_asX2DloadX2Doperand(&instance_0),
        1u,
        "WAST line 267: as-load-operand()"
    );
    assertEqualU32(
        m8_globalX2E0Export20_asX2DmemoryX2EgrowX2Dvalue(&instance_0),
        1u,
        "WAST line 268: as-memory.grow-value()"
    );
    assertEqualU32(
        m8_globalX2E0Export13_asX2DcallX2Dvalue(&instance_0),
        6u,
        "WAST line 270: as-call-value()"
    );
    assertEqualU32(
        m8_globalX2E0Export15_asX2DreturnX2Dvalue(&instance_0),
        6u,
        "WAST line 272: as-return-value()"
    );
    (void)(m8_globalX2E0Export15_asX2DdropX2Doperand(&instance_0));
    printOK("WAST line 273: as-drop-operand()");
    assertEqualU32(
        m8_globalX2E0Export11_asX2DbrX2Dvalue(&instance_0),
        6u,
        "WAST line 274: as-br-value()"
    );
    assertEqualU32(
        m8_globalX2E0Export18_asX2DlocalX2EsetX2Dvalue(&instance_0, 1u),
        6u,
        "WAST line 276: as-local.set-value(1u)"
    );
    assertEqualU32(
        m8_globalX2E0Export18_asX2DlocalX2EteeX2Dvalue(&instance_0, 1u),
        6u,
        "WAST line 277: as-local.tee-value(1u)"
    );
    assertEqualU32(
        m8_globalX2E0Export19_asX2DglobalX2EsetX2Dvalue(&instance_0),
        6u,
        "WAST line 278: as-global.set-value()"
    );
    assertEqualU32(
        m8_globalX2E0Export16_asX2DunaryX2Doperand(&instance_0),
        0u,
        "WAST line 280: as-unary-operand()"
    );
    assertEqualU32(
        m8_globalX2E0Export17_asX2DbinaryX2Doperand(&instance_0),
        36u,
        "WAST line 281: as-binary-operand()"
    );
    assertEqualU32(
        m8_globalX2E0Export18_asX2DcompareX2Doperand(&instance_0),
        1u,
        "WAST line 282: as-compare-operand()"
    );
    m8_globalX2E3Instantiate(&instance_1, resolveTestImports);
    printStart("global.3.wasm");
    m8_globalX2E4Instantiate(&instance_2, resolveTestImports);
    printStart("global.4.wasm");
    m9_globalX2E18Instantiate(&instance_3, resolveTestImports);
    printStart("global.18.wasm");
    m9_globalX2E19Instantiate(&instance_4, resolveTestImports);
    printStart("global.19.wasm");
    m9_globalX2E23Instantiate(&instance_5, resolveTestImports);
    printStart("global.23.wasm");
    m9_globalX2E26Instantiate(&instance_6, resolveTestImports);
    printStart("global.26.wasm");
    m9_globalX2E49Instantiate(&instance_7, resolveTestImports);
    printStart("global.49.wasm");
    bindTestImport("G", "g", (void*)m9_globalX2E49Export1_g(&instance_7));
    m9_globalX2E50Instantiate(&instance_8, resolveTestImports);
    printStart("global.50.wasm");
    assertEqualU32((m9_globalX2E50Export8_getX2Delem(&instance_8, 0u)).func == NULL, 1u, "WAST line 658: get-elem(0u)");
    assertEqualU32((m9_globalX2E50Export8_getX2Delem(&instance_8, 4u)).func != NULL, 1u, "WAST line 659: get-elem(4u)");
    assertEqualU32((m9_globalX2E50Export8_getX2Delem(&instance_8, 8u)).func != NULL, 1u, "WAST line 660: get-elem(8u)");
    assertEqualU32(
        m9_globalX2E50Export8_getX2Ddata(&instance_8, 4u),
        1145324612u,
        "WAST line 662: get-data(4u)"
    );
    assertEqualU32(
        m9_globalX2E50Export8_getX2Ddata(&instance_8, 8u),
        2290649224u,
        "WAST line 663: get-data(8u)"
    );
    m9_globalX2E50FreeInstance(&instance_8);
    m9_globalX2E49FreeInstance(&instance_7);
    m9_globalX2E26FreeInstance(&instance_6);
    m9_globalX2E23FreeInstance(&instance_5);
    m9_globalX2E19FreeInstance(&instance_4);
    m9_globalX2E18FreeInstance(&instance_3);
    m8_globalX2E4FreeInstance(&instance_2);
    m8_globalX2E3FreeInstance(&instance_1);
    m8_globalX2E0FreeInstance(&instance_0);
}
