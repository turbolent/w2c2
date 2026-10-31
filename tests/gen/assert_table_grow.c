#include "test.h"
#include "test_table_grow.0.h"
#include "test_table_grow.1.h"
#include "test_table_grow.2.h"
#include "test_table_grow.3.h"
#include "test_table_grow.4.h"
#include "test_table_grow.5.h"
#include "test_table_grow.6.h"
#include "test_table_grow.7.h"
#include "test_table_grow.15.h"

static m12_tableX5FgrowX2E0Instance instance_0;
static m12_tableX5FgrowX2E1Instance instance_1;
static m12_tableX5FgrowX2E2Instance instance_2;
static m12_tableX5FgrowX2E3Instance instance_3;
static m12_tableX5FgrowX2E4Instance instance_4;
static m12_tableX5FgrowX2E5Instance instance_5;
static m12_tableX5FgrowX2E6Instance instance_6;
static m12_tableX5FgrowX2E7Instance instance_7;
static m13_tableX5FgrowX2E15Instance instance_8;

void test(void) {
    m12_tableX5FgrowX2E0Instantiate(&instance_0, resolveTestImports);
    printStart("table_grow.0.wasm");
    assertEqualU32(
        m12_tableX5FgrowX2E0Export4_size(&instance_0),
        0u,
        "WAST line 17: size()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_tableX5FgrowX2E0Export3_set(&instance_0, 0u, testExternRef(2u)), "WAST line 18: set(0u, testExternRef(2u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_tableX5FgrowX2E0Export3_get(&instance_0, 0u), "WAST line 19: get(0u)");
#endif
    assertEqualU32(
        m12_tableX5FgrowX2E0Export4_grow(&instance_0, 1u, wasmNullExternRef),
        0u,
        "WAST line 21: grow(1u, wasmNullExternRef)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E0Export4_size(&instance_0),
        1u,
        "WAST line 22: size()"
    );
    assertEqualU32((m12_tableX5FgrowX2E0Export3_get(&instance_0, 0u)) == wasmNullExternRef, 1u, "WAST line 23: get(0u)");
    (void)(m12_tableX5FgrowX2E0Export3_set(&instance_0, 0u, testExternRef(2u)));
    printOK("WAST line 24: set(0u, testExternRef(2u))");
    assertEqualU32((m12_tableX5FgrowX2E0Export3_get(&instance_0, 0u)) == testExternRef(2u), 1u, "WAST line 25: get(0u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_tableX5FgrowX2E0Export3_set(&instance_0, 1u, testExternRef(2u)), "WAST line 26: set(1u, testExternRef(2u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_tableX5FgrowX2E0Export3_get(&instance_0, 1u), "WAST line 27: get(1u)");
#endif
    assertEqualU32(
        m12_tableX5FgrowX2E0Export11_growX2Dabbrev(&instance_0, 4u, testExternRef(3u)),
        1u,
        "WAST line 29: grow-abbrev(4u, testExternRef(3u))"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E0Export4_size(&instance_0),
        5u,
        "WAST line 30: size()"
    );
    assertEqualU32((m12_tableX5FgrowX2E0Export3_get(&instance_0, 0u)) == testExternRef(2u), 1u, "WAST line 31: get(0u)");
    (void)(m12_tableX5FgrowX2E0Export3_set(&instance_0, 0u, testExternRef(2u)));
    printOK("WAST line 32: set(0u, testExternRef(2u))");
    assertEqualU32((m12_tableX5FgrowX2E0Export3_get(&instance_0, 0u)) == testExternRef(2u), 1u, "WAST line 33: get(0u)");
    assertEqualU32((m12_tableX5FgrowX2E0Export3_get(&instance_0, 1u)) == testExternRef(3u), 1u, "WAST line 34: get(1u)");
    assertEqualU32((m12_tableX5FgrowX2E0Export3_get(&instance_0, 4u)) == testExternRef(3u), 1u, "WAST line 35: get(4u)");
    (void)(m12_tableX5FgrowX2E0Export3_set(&instance_0, 4u, testExternRef(4u)));
    printOK("WAST line 36: set(4u, testExternRef(4u))");
    assertEqualU32((m12_tableX5FgrowX2E0Export3_get(&instance_0, 4u)) == testExternRef(4u), 1u, "WAST line 37: get(4u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_tableX5FgrowX2E0Export3_set(&instance_0, 5u, testExternRef(2u)), "WAST line 38: set(5u, testExternRef(2u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_tableX5FgrowX2E0Export3_get(&instance_0, 5u), "WAST line 39: get(5u)");
#endif
    m12_tableX5FgrowX2E1Instantiate(&instance_1, resolveTestImports);
    printStart("table_grow.1.wasm");
    assertEqualU32(
        m12_tableX5FgrowX2E1Export4_grow(&instance_1),
        4294967295u,
        "WAST line 51: grow()"
    );
    m12_tableX5FgrowX2E2Instantiate(&instance_2, resolveTestImports);
    printStart("table_grow.2.wasm");
    assertEqualU32(
        m12_tableX5FgrowX2E2Export4_grow(&instance_2, 0u),
        0u,
        "WAST line 61: grow(0u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E2Export4_grow(&instance_2, 1u),
        0u,
        "WAST line 62: grow(1u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E2Export4_grow(&instance_2, 0u),
        1u,
        "WAST line 63: grow(0u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E2Export4_grow(&instance_2, 2u),
        1u,
        "WAST line 64: grow(2u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E2Export4_grow(&instance_2, 800u),
        3u,
        "WAST line 65: grow(800u)"
    );
    m12_tableX5FgrowX2E3Instantiate(&instance_3, resolveTestImports);
    printStart("table_grow.3.wasm");
    assertEqualU32(
        m12_tableX5FgrowX2E3Export4_grow(&instance_3, 0u),
        0u,
        "WAST line 75: grow(0u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E3Export4_grow(&instance_3, 1u),
        0u,
        "WAST line 76: grow(1u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E3Export4_grow(&instance_3, 1u),
        1u,
        "WAST line 77: grow(1u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E3Export4_grow(&instance_3, 2u),
        2u,
        "WAST line 78: grow(2u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E3Export4_grow(&instance_3, 6u),
        4u,
        "WAST line 79: grow(6u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E3Export4_grow(&instance_3, 0u),
        10u,
        "WAST line 80: grow(0u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E3Export4_grow(&instance_3, 1u),
        4294967295u,
        "WAST line 81: grow(1u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E3Export4_grow(&instance_3, 65536u),
        4294967295u,
        "WAST line 82: grow(65536u)"
    );
    m12_tableX5FgrowX2E4Instantiate(&instance_4, resolveTestImports);
    printStart("table_grow.4.wasm");
    assertEqualU32((m12_tableX5FgrowX2E4Export16_checkX2DtableX2Dnull(&instance_4, 0u, 9u)).func == NULL, 1u, "WAST line 107: check-table-null(0u, 9u)");
    assertEqualU32(
        m12_tableX5FgrowX2E4Export4_grow(&instance_4, 10u),
        10u,
        "WAST line 108: grow(10u)"
    );
    assertEqualU32((m12_tableX5FgrowX2E4Export16_checkX2DtableX2Dnull(&instance_4, 0u, 19u)).func == NULL, 1u, "WAST line 109: check-table-null(0u, 19u)");
    m12_tableX5FgrowX2E5Instantiate(&instance_5, resolveTestImports);
    printStart("table_grow.5.wasm");
    bindTestImport("grown-table", "table", (void*)m12_tableX5FgrowX2E5Export5_table(&instance_5));
    assertEqualU32(
        m12_tableX5FgrowX2E5Export4_grow(&instance_5),
        1u,
        "WAST line 117: grow()"
    );
    m12_tableX5FgrowX2E6Instantiate(&instance_6, resolveTestImports);
    printStart("table_grow.6.wasm");
    bindTestImport("grown-imported-table", "table", (void*)m12_tableX5FgrowX2E6Export5_table(&instance_6));
    assertEqualU32(
        m12_tableX5FgrowX2E6Export4_grow(&instance_6),
        2u,
        "WAST line 124: grow()"
    );
    m12_tableX5FgrowX2E7Instantiate(&instance_7, resolveTestImports);
    printStart("table_grow.7.wasm");
    assertEqualU32(
        m12_tableX5FgrowX2E7Export4_size(&instance_7),
        3u,
        "WAST line 130: size()"
    );
    m13_tableX5FgrowX2E15Instantiate(&instance_8, resolveTestImports);
    printStart("table_grow.15.wasm");
    assertEqualU32(
        m13_tableX5FgrowX2E15Export4_grow(&instance_8, 4294967295u),
        4294967295u,
        "WAST line 208: grow(4294967295u)"
    );
    assertEqualU32(
        m13_tableX5FgrowX2E15Export4_size(&instance_8),
        1u,
        "WAST line 209: size()"
    );
    m13_tableX5FgrowX2E15FreeInstance(&instance_8);
    m12_tableX5FgrowX2E7FreeInstance(&instance_7);
    m12_tableX5FgrowX2E6FreeInstance(&instance_6);
    m12_tableX5FgrowX2E5FreeInstance(&instance_5);
    m12_tableX5FgrowX2E4FreeInstance(&instance_4);
    m12_tableX5FgrowX2E3FreeInstance(&instance_3);
    m12_tableX5FgrowX2E2FreeInstance(&instance_2);
    m12_tableX5FgrowX2E1FreeInstance(&instance_1);
    m12_tableX5FgrowX2E0FreeInstance(&instance_0);
}
