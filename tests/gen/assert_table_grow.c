#include "test.h"
#include "test_table_grow.0.h"
#include "test_table_grow.1.h"
#include "test_table_grow.2.h"
#include "test_table_grow.3.h"
#include "test_table_grow.4.h"
#include "test_table_grow.5.h"

static m12_tableX5FgrowX2E0Instance instance_0;
static m12_tableX5FgrowX2E1Instance instance_1;
static m12_tableX5FgrowX2E2Instance instance_2;
static m12_tableX5FgrowX2E3Instance instance_3;
static m12_tableX5FgrowX2E4Instance instance_4;
static m12_tableX5FgrowX2E5Instance instance_5;

void test(void) {
    m12_tableX5FgrowX2E0Instantiate(&instance_0, resolveTestImports);
    printStart("table_grow.0.wasm");
    assertEqualU32(
        m12_tableX5FgrowX2E0Export4_grow(&instance_0),
        4294967295u,
        "WAST line 52: grow()"
    );
    m12_tableX5FgrowX2E1Instantiate(&instance_1, resolveTestImports);
    printStart("table_grow.1.wasm");
    assertEqualU32((m12_tableX5FgrowX2E1Export16_checkX2DtableX2Dnull(&instance_1, 0u, 9u)).func == NULL, 1u, "WAST line 110: check-table-null(0u, 9u)");
    assertEqualU32(
        m12_tableX5FgrowX2E1Export4_grow(&instance_1, 10u),
        10u,
        "WAST line 111: grow(10u)"
    );
    assertEqualU32((m12_tableX5FgrowX2E1Export16_checkX2DtableX2Dnull(&instance_1, 0u, 19u)).func == NULL, 1u, "WAST line 112: check-table-null(0u, 19u)");
    m12_tableX5FgrowX2E2Instantiate(&instance_2, resolveTestImports);
    printStart("table_grow.2.wasm");
    bindTestImport("grown-table", "table", (void*)m12_tableX5FgrowX2E2Export5_table(&instance_2));
    assertEqualU32(
        m12_tableX5FgrowX2E2Export4_grow(&instance_2),
        1u,
        "WAST line 120: grow()"
    );
    m12_tableX5FgrowX2E3Instantiate(&instance_3, resolveTestImports);
    printStart("table_grow.3.wasm");
    bindTestImport("grown-imported-table", "table", (void*)m12_tableX5FgrowX2E3Export5_table(&instance_3));
    assertEqualU32(
        m12_tableX5FgrowX2E3Export4_grow(&instance_3),
        2u,
        "WAST line 127: grow()"
    );
    m12_tableX5FgrowX2E4Instantiate(&instance_4, resolveTestImports);
    printStart("table_grow.4.wasm");
    assertEqualU32(
        m12_tableX5FgrowX2E4Export4_size(&instance_4),
        3u,
        "WAST line 133: size()"
    );
    m12_tableX5FgrowX2E5Instantiate(&instance_5, resolveTestImports);
    printStart("table_grow.5.wasm");
    assertEqualU32(
        m12_tableX5FgrowX2E5Export4_grow(&instance_5, 4294967295u),
        4294967295u,
        "WAST line 212: grow(4294967295u)"
    );
    assertEqualU32(
        m12_tableX5FgrowX2E5Export4_size(&instance_5),
        1u,
        "WAST line 213: size()"
    );
    m12_tableX5FgrowX2E5FreeInstance(&instance_5);
    m12_tableX5FgrowX2E4FreeInstance(&instance_4);
    m12_tableX5FgrowX2E3FreeInstance(&instance_3);
    m12_tableX5FgrowX2E2FreeInstance(&instance_2);
    m12_tableX5FgrowX2E1FreeInstance(&instance_1);
    m12_tableX5FgrowX2E0FreeInstance(&instance_0);
}
