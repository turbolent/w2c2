#include "test.h"
#include "test_table_operations.0.h"
#include "test_table_operations.1.h"
#include "test_table_operations.2.h"
#include "test_table_operations.3.h"
#include "test_table_operations.4.h"
#include "test_table_operations.5.h"
#include "test_table_operations.6.h"

static m18_tableX5FoperationsX2E0Instance instance_0;
static m18_tableX5FoperationsX2E1Instance instance_1;
static m18_tableX5FoperationsX2E2Instance instance_2;
static m18_tableX5FoperationsX2E3Instance instance_3;
static m18_tableX5FoperationsX2E4Instance instance_4;
static m18_tableX5FoperationsX2E5Instance instance_5;
static m18_tableX5FoperationsX2E6Instance instance_6;

struct w2c2_result_ri m18_tableX5FoperationsX2E1Import5_owner9_recursive(wasmModuleInstance* instance, U32 p0) {
    (void)instance;
    return m18_tableX5FoperationsX2E0Export9_recursive(&instance_0, p0);
}
wasmTableEntry m18_tableX5FoperationsX2E4Import8_producer3_ref(wasmModuleInstance* instance) {
    (void)instance;
    return m18_tableX5FoperationsX2E3Export3_ref(&instance_3);
}
wasmTableEntry m18_tableX5FoperationsX2E6Import8_producer3_ref(wasmModuleInstance* instance) {
    (void)instance;
    return m18_tableX5FoperationsX2E5Export3_ref(&instance_5);
}
void test(void) {
    m18_tableX5FoperationsX2E0Instantiate(&instance_0, resolveTestImports);
    printStart("table_operations.0.wasm");
    bindTestImport("owner", "table", (void*)m18_tableX5FoperationsX2E0Export5_table(&instance_0));
    bindTestImport("owner", "ref", (void*)m18_tableX5FoperationsX2E0Export3_ref(&instance_0));
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 0u),
        42u,
        "WAST line 77: call(0u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 1u),
        73u,
        "WAST line 78: call(1u)"
    );
    assertEqualU32((m18_tableX5FoperationsX2E0Export3_get(&instance_0, 2u)).func == NULL, 1u, "WAST line 79: get(2u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export4_call(&instance_0, 2u), "WAST line 80: call(2u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export4_call(&instance_0, 3u), "WAST line 81: call(3u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export3_get(&instance_0, 6u), "WAST line 82: get(6u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export3_get(&instance_0, 4294967295u), "WAST line 83: get(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export3_set(&instance_0, 6u, wasmNullFuncRef), "WAST line 84: set(6u, wasmNullFuncRef)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export3_set(&instance_0, 4294967295u, wasmNullFuncRef), "WAST line 85: set(4294967295u, wasmNullFuncRef)");
#endif
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 0u),
        42u,
        "WAST line 86: call(0u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 1u),
        73u,
        "WAST line 87: call(1u)"
    );
    (void)(m18_tableX5FoperationsX2E0Export4_copy(&instance_0, 1u, 0u, 4u));
    printOK("WAST line 88: copy(1u, 0u, 4u)");
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 1u),
        42u,
        "WAST line 89: call(1u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 2u),
        73u,
        "WAST line 90: call(2u)"
    );
    assertEqualU32((m18_tableX5FoperationsX2E0Export3_get(&instance_0, 3u)).func == NULL, 1u, "WAST line 91: get(3u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export4_call(&instance_0, 4u), "WAST line 92: call(4u)");
#endif
    (void)(m18_tableX5FoperationsX2E0Export4_copy(&instance_0, 0u, 1u, 4u));
    printOK("WAST line 93: copy(0u, 1u, 4u)");
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 0u),
        42u,
        "WAST line 94: call(0u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 1u),
        73u,
        "WAST line 95: call(1u)"
    );
    (void)(m18_tableX5FoperationsX2E0Export4_init(&instance_0, 4u, 0u, 2u));
    printOK("WAST line 96: init(4u, 0u, 2u)");
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 4u),
        73u,
        "WAST line 97: call(4u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 5u),
        42u,
        "WAST line 98: call(5u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export4_fill(&instance_0, 5u, 2u), "WAST line 99: fill(5u, 2u)");
#endif
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 5u),
        42u,
        "WAST line 100: call(5u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export4_copy(&instance_0, 0u, 5u, 2u), "WAST line 101: copy(0u, 5u, 2u)");
#endif
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 0u),
        42u,
        "WAST line 102: call(0u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export4_init(&instance_0, 0u, 1u, 2u), "WAST line 103: init(0u, 1u, 2u)");
#endif
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 0u),
        42u,
        "WAST line 104: call(0u)"
    );
    (void)(m18_tableX5FoperationsX2E0Export4_drop(&instance_0));
    printOK("WAST line 105: drop()");
    (void)(m18_tableX5FoperationsX2E0Export4_drop(&instance_0));
    printOK("WAST line 106: drop()");
    (void)(m18_tableX5FoperationsX2E0Export4_init(&instance_0, 6u, 0u, 0u));
    printOK("WAST line 107: init(6u, 0u, 0u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export4_init(&instance_0, 0u, 0u, 1u), "WAST line 108: init(0u, 0u, 1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export4_init(&instance_0, 0u, 1u, 0u), "WAST line 109: init(0u, 1u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export4_init(&instance_0, 7u, 0u, 0u), "WAST line 110: init(7u, 0u, 0u)");
#endif
    (void)(m18_tableX5FoperationsX2E0Export6_active(&instance_0, 0u));
    printOK("WAST line 111: active(0u)");
    (void)(m18_tableX5FoperationsX2E0Export8_declared(&instance_0, 0u));
    printOK("WAST line 112: declared(0u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export6_active(&instance_0, 1u), "WAST line 113: active(1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export8_declared(&instance_0, 1u), "WAST line 114: declared(1u)");
#endif
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_grow(&instance_0, 0u),
        6u,
        "WAST line 115: grow(0u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_grow(&instance_0, 2u),
        6u,
        "WAST line 116: grow(2u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 7u),
        42u,
        "WAST line 117: call(7u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_grow(&instance_0, 1u),
        4294967295u,
        "WAST line 118: grow(1u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_grow(&instance_0, 4294967295u),
        4294967295u,
        "WAST line 119: grow(4294967295u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_size(&instance_0),
        8u,
        "WAST line 120: size()"
    );
    (void)(m18_tableX5FoperationsX2E0Export16_initX2Dexpressions(&instance_0, 6u, 0u, 2u));
    printOK("WAST line 121: init-expressions(6u, 0u, 2u)");
    assertEqualU32((m18_tableX5FoperationsX2E0Export3_get(&instance_0, 6u)).func == NULL, 1u, "WAST line 122: get(6u)");
    assertEqualU32(
        m18_tableX5FoperationsX2E0Export4_call(&instance_0, 7u),
        42u,
        "WAST line 123: call(7u)"
    );
    assertEqualU32((m18_tableX5FoperationsX2E0Export10_nullX2Dlocal(&instance_0)).func == NULL, 1u, "WAST line 124: null-local()");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export8_trapX2Dref(&instance_0), "WAST line 125: trap-ref()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E0Export9_trapX2Dpair(&instance_0), "WAST line 126: trap-pair()");
#endif
    assertEqualU32((m18_tableX5FoperationsX2E0Export6_select(&instance_0, 0u)).func == NULL, 1u, "WAST line 127: select(0u)");
    assertEqualU32((m18_tableX5FoperationsX2E0Export6_select(&instance_0, 1u)).func != NULL, 1u, "WAST line 128: select(1u)");
    {
        struct w2c2_result_ri result;
        result = m18_tableX5FoperationsX2E0Export9_recursive(&instance_0, 5u);
        assertEqualU32((result.v0).func != NULL, 1u, "WAST line 129: recursive(5u) result 0");
        assertEqualU32(
            result.v1,
            5u,
            "WAST line 129: recursive(5u) result 1"
        );
    }
    {
        struct w2c2_result_rir result;
        result = m18_tableX5FoperationsX2E0Export6_branch(&instance_0, 0u);
        assertEqualU32((result.v0).func == NULL, 1u, "WAST line 130: branch(0u) result 0");
        assertEqualU32(
            result.v1,
            8u,
            "WAST line 130: branch(0u) result 1"
        );
        assertEqualU32((result.v2).func != NULL, 1u, "WAST line 130: branch(0u) result 2");
    }
    {
        struct w2c2_result_rir result;
        result = m18_tableX5FoperationsX2E0Export6_branch(&instance_0, 1u);
        assertEqualU32((result.v0).func != NULL, 1u, "WAST line 131: branch(1u) result 0");
        assertEqualU32(
            result.v1,
            7u,
            "WAST line 131: branch(1u) result 1"
        );
        assertEqualU32((result.v2).func == NULL, 1u, "WAST line 131: branch(1u) result 2");
    }
    assertEqualU32((m18_tableX5FoperationsX2E0Export8_identity(&instance_0, 0u)).func != NULL, 1u, "WAST line 132: identity(0u)");
    assertEqualU32((m18_tableX5FoperationsX2E0Export8_identity(&instance_0, 1u)).func != NULL, 1u, "WAST line 133: identity(1u)");
    {
        struct w2c2_result_ri result;
        result = m18_tableX5FoperationsX2E0Export12_branchX2Dtable(&instance_0, 0u);
        assertEqualU32((result.v0).func != NULL, 1u, "WAST line 134: branch-table(0u) result 0");
        assertEqualU32(
            result.v1,
            12u,
            "WAST line 134: branch-table(0u) result 1"
        );
    }
    {
        struct w2c2_result_ri result;
        result = m18_tableX5FoperationsX2E0Export12_branchX2Dtable(&instance_0, 1u);
        assertEqualU32((result.v0).func != NULL, 1u, "WAST line 135: branch-table(1u) result 0");
        assertEqualU32(
            result.v1,
            11u,
            "WAST line 135: branch-table(1u) result 1"
        );
    }
    {
        struct w2c2_result_ri result;
        result = m18_tableX5FoperationsX2E0Export12_branchX2Dtable(&instance_0, 2u);
        assertEqualU32((result.v0).func != NULL, 1u, "WAST line 136: branch-table(2u) result 0");
        assertEqualU32(
            result.v1,
            12u,
            "WAST line 136: branch-table(2u) result 1"
        );
    }
    assertEqualU32((m18_tableX5FoperationsX2E0Export4_loop(&instance_0)).func != NULL, 1u, "WAST line 137: loop()");
    assertEqualU32((m18_tableX5FoperationsX2E0Export12_indirectX2Dref(&instance_0)).func != NULL, 1u, "WAST line 138: indirect-ref()");
    assertEqualU32((m18_tableX5FoperationsX2E0Export4_dead(&instance_0)).func != NULL, 1u, "WAST line 139: dead()");
    m18_tableX5FoperationsX2E1Instantiate(&instance_1, resolveTestImports);
    printStart("table_operations.1.wasm");
    (void)(m18_tableX5FoperationsX2E1Export4_copy(&instance_1));
    printOK("WAST line 156: copy()");
    assertEqualU32(
        m18_tableX5FoperationsX2E1Export4_call(&instance_1, 1u),
        42u,
        "WAST line 157: call(1u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E1Export4_call(&instance_1, 2u),
        73u,
        "WAST line 158: call(2u)"
    );
    (void)(m18_tableX5FoperationsX2E1Export4_init(&instance_1));
    printOK("WAST line 159: init()");
    {
        struct w2c2_result_ri result;
        result = m18_tableX5FoperationsX2E1Export7_forward(&instance_1);
        assertEqualU32((result.v0).func != NULL, 1u, "WAST line 160: forward() result 0");
        assertEqualU32(
            result.v1,
            3u,
            "WAST line 160: forward() result 1"
        );
    }
    assertEqualU32(
        m18_tableX5FoperationsX2E1Export4_call(&instance_1, 0u),
        42u,
        "WAST line 161: call(0u)"
    );
    bindTestImport("aliases", "table", (void*)m18_tableX5FoperationsX2E1Export5_table(&instance_1));
    m18_tableX5FoperationsX2E2Instantiate(&instance_2, resolveTestImports);
    printStart("table_operations.2.wasm");
    (void)(m18_tableX5FoperationsX2E2Export5_clear(&instance_2));
    printOK("WAST line 168: clear()");
    assertEqualU32((m18_tableX5FoperationsX2E0Export3_get(&instance_0, 0u)).func == NULL, 1u, "WAST line 169: get(0u)");
    m18_tableX5FoperationsX2E3Instantiate(&instance_3, resolveTestImports);
    printStart("table_operations.3.wasm");
    m18_tableX5FoperationsX2E4Instantiate(&instance_4, resolveTestImports);
    printStart("table_operations.4.wasm");
    assertEqualU32(
        m18_tableX5FoperationsX2E4Export4_call(&instance_4),
        91u,
        "WAST line 184: call()"
    );
    m18_tableX5FoperationsX2E5Instantiate(&instance_5, resolveTestImports);
    printStart("table_operations.5.wasm");
    assertEqualU32(
        m18_tableX5FoperationsX2E4Export4_call(&instance_4),
        91u,
        "WAST line 192: call()"
    );
    m18_tableX5FoperationsX2E6Instantiate(&instance_6, resolveTestImports);
    printStart("table_operations.6.wasm");
    assertEqualU32(
        m18_tableX5FoperationsX2E6Export4_call(&instance_6),
        92u,
        "WAST line 199: call()"
    );
    m18_tableX5FoperationsX2E6FreeInstance(&instance_6);
    m18_tableX5FoperationsX2E5FreeInstance(&instance_5);
    m18_tableX5FoperationsX2E4FreeInstance(&instance_4);
    m18_tableX5FoperationsX2E3FreeInstance(&instance_3);
    m18_tableX5FoperationsX2E2FreeInstance(&instance_2);
    m18_tableX5FoperationsX2E1FreeInstance(&instance_1);
    m18_tableX5FoperationsX2E0FreeInstance(&instance_0);
}
