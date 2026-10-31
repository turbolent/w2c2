#include "test.h"
#include "test_table_operations.0.h"
#include "test_table_operations.1.h"
#include "test_table_operations.2.h"
#include "test_table_operations.3.h"
#include "test_table_operations.4.h"
#include "test_table_operations.5.h"
#include "test_table_operations.6.h"
#include "test_table_operations.7.h"
#include "test_table_operations.8.h"
#include "test_table_operations.9.h"

static m18_tableX5FoperationsX2E0Instance instance_0;
static m18_tableX5FoperationsX2E1Instance instance_1;
static m18_tableX5FoperationsX2E2Instance instance_2;
static m18_tableX5FoperationsX2E3Instance instance_3;
static m18_tableX5FoperationsX2E4Instance instance_4;
static m18_tableX5FoperationsX2E5Instance instance_5;
static m18_tableX5FoperationsX2E6Instance instance_6;
static m18_tableX5FoperationsX2E7Instance instance_7;
static m18_tableX5FoperationsX2E8Instance instance_8;
static m18_tableX5FoperationsX2E9Instance instance_9;

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
struct w2c2_result_er m18_tableX5FoperationsX2E8Import6_extern4_pair(wasmModuleInstance* instance, wasmExternRef p0) {
    (void)instance;
    return m18_tableX5FoperationsX2E7Export4_pair(&instance_7, p0);
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
    m18_tableX5FoperationsX2E7Instantiate(&instance_7, resolveTestImports);
    printStart("table_operations.7.wasm");
    bindTestImport("extern", "host", (void*)m18_tableX5FoperationsX2E7Export4_host(&instance_7));
    bindTestImport("extern", "table", (void*)m18_tableX5FoperationsX2E7Export5_table(&instance_7));
    assertEqualU32((*m18_tableX5FoperationsX2E7Export4_host(&instance_7)) == testExternRef(0u), 1u, "WAST line 291: get host");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 0u)) == wasmNullExternRef, 1u, "WAST line 292: get(0u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 1u)) == testExternRef(0u), 1u, "WAST line 293: get(1u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export10_nullX2Dlocal(&instance_7)) == wasmNullExternRef, 1u, "WAST line 294: null-local()");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export8_trapX2Dref(&instance_7), "WAST line 295: trap-ref()");
#endif
    assertEqualU32((m18_tableX5FoperationsX2E7Export10_getX2Dglobal(&instance_7)) == wasmNullExternRef, 1u, "WAST line 296: get-global()");
    (void)(m18_tableX5FoperationsX2E7Export10_setX2Dglobal(&instance_7, testExternRef(4294967295u)));
    printOK("WAST line 297: set-global(testExternRef(4294967295u))");
    assertEqualU32((m18_tableX5FoperationsX2E7Export10_getX2Dglobal(&instance_7)) == testExternRef(4294967295u), 1u, "WAST line 298: get-global()");
    assertEqualU32(
        m18_tableX5FoperationsX2E7Export7_isX2Dnull(&instance_7, testExternRef(0u)),
        0u,
        "WAST line 299: is-null(testExternRef(0u))"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E7Export7_isX2Dnull(&instance_7, wasmNullExternRef),
        1u,
        "WAST line 300: is-null(wasmNullExternRef)"
    );
    {
        struct w2c2_result_er result;
        result = m18_tableX5FoperationsX2E7Export4_pair(&instance_7, testExternRef(0u));
        assertEqualU32((result.v0) == testExternRef(0u), 1u, "WAST line 301: pair(testExternRef(0u)) result 0");
        assertEqualU32((result.v1).func != NULL, 1u, "WAST line 301: pair(testExternRef(0u)) result 1");
    }
    assertEqualU32(
        m18_tableX5FoperationsX2E7Export5_calls(&instance_7),
        1u,
        "WAST line 302: calls()"
    );
    {
        struct w2c2_result_er result;
        result = m18_tableX5FoperationsX2E7Export8_indirect(&instance_7, testExternRef(1u));
        assertEqualU32((result.v0) == testExternRef(1u), 1u, "WAST line 303: indirect(testExternRef(1u)) result 0");
        assertEqualU32((result.v1).func != NULL, 1u, "WAST line 303: indirect(testExternRef(1u)) result 1");
    }
    assertEqualU32(
        m18_tableX5FoperationsX2E7Export5_calls(&instance_7),
        2u,
        "WAST line 304: calls()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export15_wrongX2Dparameter(&instance_7), "WAST line 305: wrong-parameter()");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export12_wrongX2Dresult(&instance_7), "WAST line 306: wrong-result()");
#endif
    assertEqualU32((m18_tableX5FoperationsX2E7Export6_select(&instance_7, testExternRef(0u), testExternRef(1u), 1u)) == testExternRef(0u), 1u, "WAST line 307: select(testExternRef(0u), testExternRef(1u), 1u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export6_select(&instance_7, testExternRef(0u), wasmNullExternRef, 0u)) == wasmNullExternRef, 1u, "WAST line 308: select(testExternRef(0u), wasmNullExternRef, 0u)");
    {
        struct w2c2_result_ei result;
        result = m18_tableX5FoperationsX2E7Export9_recursive(&instance_7, testExternRef(2u), 5u);
        assertEqualU32((result.v0) == testExternRef(2u), 1u, "WAST line 309: recursive(testExternRef(2u), 5u) result 0");
        assertEqualU32(
            result.v1,
            5u,
            "WAST line 309: recursive(testExternRef(2u), 5u) result 1"
        );
    }
    {
        struct w2c2_result_eie result;
        result = m18_tableX5FoperationsX2E7Export6_branch(&instance_7, testExternRef(3u), 1u);
        assertEqualU32((result.v0) == testExternRef(3u), 1u, "WAST line 310: branch(testExternRef(3u), 1u) result 0");
        assertEqualU32(
            result.v1,
            7u,
            "WAST line 310: branch(testExternRef(3u), 1u) result 1"
        );
        assertEqualU32((result.v2) == wasmNullExternRef, 1u, "WAST line 310: branch(testExternRef(3u), 1u) result 2");
    }
    {
        struct w2c2_result_eie result;
        result = m18_tableX5FoperationsX2E7Export6_branch(&instance_7, testExternRef(3u), 0u);
        assertEqualU32((result.v0) == wasmNullExternRef, 1u, "WAST line 311: branch(testExternRef(3u), 0u) result 0");
        assertEqualU32(
            result.v1,
            8u,
            "WAST line 311: branch(testExternRef(3u), 0u) result 1"
        );
        assertEqualU32((result.v2) == testExternRef(3u), 1u, "WAST line 311: branch(testExternRef(3u), 0u) result 2");
    }
    {
        struct w2c2_result_ei result;
        result = m18_tableX5FoperationsX2E7Export12_branchX2Dtable(&instance_7, testExternRef(4u), 0u);
        assertEqualU32((result.v0) == testExternRef(4u), 1u, "WAST line 312: branch-table(testExternRef(4u), 0u) result 0");
        assertEqualU32(
            result.v1,
            12u,
            "WAST line 312: branch-table(testExternRef(4u), 0u) result 1"
        );
    }
    {
        struct w2c2_result_ei result;
        result = m18_tableX5FoperationsX2E7Export12_branchX2Dtable(&instance_7, testExternRef(4u), 1u);
        assertEqualU32((result.v0) == testExternRef(4u), 1u, "WAST line 313: branch-table(testExternRef(4u), 1u) result 0");
        assertEqualU32(
            result.v1,
            11u,
            "WAST line 313: branch-table(testExternRef(4u), 1u) result 1"
        );
    }
    {
        struct w2c2_result_ei result;
        result = m18_tableX5FoperationsX2E7Export12_branchX2Dtable(&instance_7, testExternRef(4u), 2u);
        assertEqualU32((result.v0) == testExternRef(4u), 1u, "WAST line 314: branch-table(testExternRef(4u), 2u) result 0");
        assertEqualU32(
            result.v1,
            12u,
            "WAST line 314: branch-table(testExternRef(4u), 2u) result 1"
        );
    }
    assertEqualU32((m18_tableX5FoperationsX2E7Export8_identity(&instance_7, testExternRef(5u), 0u)) == testExternRef(5u), 1u, "WAST line 315: identity(testExternRef(5u), 0u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export8_identity(&instance_7, testExternRef(5u), 1u)) == testExternRef(5u), 1u, "WAST line 316: identity(testExternRef(5u), 1u)");
    {
        struct w2c2_result_ei result;
        result = m18_tableX5FoperationsX2E7Export5_block(&instance_7, testExternRef(5u));
        assertEqualU32((result.v0) == testExternRef(5u), 1u, "WAST line 317: block(testExternRef(5u)) result 0");
        assertEqualU32(
            result.v1,
            42u,
            "WAST line 317: block(testExternRef(5u)) result 1"
        );
    }
    {
        struct w2c2_result_ei result;
        result = m18_tableX5FoperationsX2E7Export2_if(&instance_7, testExternRef(5u), 0u);
        assertEqualU32((result.v0) == testExternRef(5u), 1u, "WAST line 318: if(testExternRef(5u), 0u) result 0");
        assertEqualU32(
            result.v1,
            2u,
            "WAST line 318: if(testExternRef(5u), 0u) result 1"
        );
    }
    {
        struct w2c2_result_ei result;
        result = m18_tableX5FoperationsX2E7Export2_if(&instance_7, testExternRef(5u), 1u);
        assertEqualU32((result.v0) == testExternRef(5u), 1u, "WAST line 319: if(testExternRef(5u), 1u) result 0");
        assertEqualU32(
            result.v1,
            1u,
            "WAST line 319: if(testExternRef(5u), 1u) result 1"
        );
    }
    assertEqualU32((m18_tableX5FoperationsX2E7Export4_loop(&instance_7, testExternRef(6u))) == testExternRef(6u), 1u, "WAST line 320: loop(testExternRef(6u))");
    assertEqualU32((m18_tableX5FoperationsX2E7Export14_functionX2Dlabel(&instance_7, testExternRef(7u))) == testExternRef(7u), 1u, "WAST line 321: function-label(testExternRef(7u))");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_dead(&instance_7), "WAST line 322: dead()");
#endif
    (void)(m18_tableX5FoperationsX2E7Export3_set(&instance_7, 0u, testExternRef(1u)));
    printOK("WAST line 325: set(0u, testExternRef(1u))");
    (void)(m18_tableX5FoperationsX2E7Export3_set(&instance_7, 1u, testExternRef(2u)));
    printOK("WAST line 326: set(1u, testExternRef(2u))");
    (void)(m18_tableX5FoperationsX2E7Export3_set(&instance_7, 2u, testExternRef(3u)));
    printOK("WAST line 327: set(2u, testExternRef(3u))");
    (void)(m18_tableX5FoperationsX2E7Export4_copy(&instance_7, 1u, 0u, 3u));
    printOK("WAST line 328: copy(1u, 0u, 3u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 1u)) == testExternRef(1u), 1u, "WAST line 329: get(1u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 2u)) == testExternRef(2u), 1u, "WAST line 330: get(2u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 3u)) == testExternRef(3u), 1u, "WAST line 331: get(3u)");
    (void)(m18_tableX5FoperationsX2E7Export4_copy(&instance_7, 0u, 1u, 3u));
    printOK("WAST line 332: copy(0u, 1u, 3u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 0u)) == testExternRef(1u), 1u, "WAST line 333: get(0u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 1u)) == testExternRef(2u), 1u, "WAST line 334: get(1u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 2u)) == testExternRef(3u), 1u, "WAST line 335: get(2u)");
    (void)(m18_tableX5FoperationsX2E7Export11_copyX2Dsource(&instance_7, 4u, 0u, 2u));
    printOK("WAST line 336: copy-source(4u, 0u, 2u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 4u)) == testExternRef(0u), 1u, "WAST line 337: get(4u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 5u)) == wasmNullExternRef, 1u, "WAST line 338: get(5u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export3_get(&instance_7, 6u), "WAST line 339: get(6u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export3_get(&instance_7, 4294967295u), "WAST line 340: get(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export3_set(&instance_7, 6u, testExternRef(9u)), "WAST line 341: set(6u, testExternRef(9u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export3_set(&instance_7, 4294967295u, testExternRef(9u)), "WAST line 342: set(4294967295u, testExternRef(9u))");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_fill(&instance_7, 5u, testExternRef(9u), 2u), "WAST line 343: fill(5u, testExternRef(9u), 2u)");
#endif
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 5u)) == wasmNullExternRef, 1u, "WAST line 344: get(5u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_copy(&instance_7, 5u, 0u, 2u), "WAST line 345: copy(5u, 0u, 2u)");
#endif
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 5u)) == wasmNullExternRef, 1u, "WAST line 346: get(5u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_copy(&instance_7, 0u, 5u, 2u), "WAST line 347: copy(0u, 5u, 2u)");
#endif
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 0u)) == testExternRef(1u), 1u, "WAST line 348: get(0u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export11_copyX2Dsource(&instance_7, 0u, 2u, 2u), "WAST line 349: copy-source(0u, 2u, 2u)");
#endif
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 0u)) == testExternRef(1u), 1u, "WAST line 350: get(0u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_init(&instance_7, 5u, 0u, 2u), "WAST line 351: init(5u, 0u, 2u)");
#endif
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 5u)) == wasmNullExternRef, 1u, "WAST line 352: get(5u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_init(&instance_7, 0u, 2u, 2u), "WAST line 353: init(0u, 2u, 2u)");
#endif
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 0u)) == testExternRef(1u), 1u, "WAST line 354: get(0u)");
    (void)(m18_tableX5FoperationsX2E7Export4_copy(&instance_7, 6u, 6u, 0u));
    printOK("WAST line 355: copy(6u, 6u, 0u)");
    (void)(m18_tableX5FoperationsX2E7Export4_init(&instance_7, 6u, 3u, 0u));
    printOK("WAST line 356: init(6u, 3u, 0u)");
    (void)(m18_tableX5FoperationsX2E7Export4_fill(&instance_7, 6u, testExternRef(9u), 0u));
    printOK("WAST line 357: fill(6u, testExternRef(9u), 0u)");
    (void)(m18_tableX5FoperationsX2E7Export5_empty(&instance_7));
    printOK("WAST line 358: empty()");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_fill(&instance_7, 7u, testExternRef(9u), 0u), "WAST line 359: fill(7u, testExternRef(9u), 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_copy(&instance_7, 7u, 6u, 0u), "WAST line 360: copy(7u, 6u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_copy(&instance_7, 6u, 7u, 0u), "WAST line 361: copy(6u, 7u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_init(&instance_7, 7u, 3u, 0u), "WAST line 362: init(7u, 3u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_init(&instance_7, 6u, 4u, 0u), "WAST line 363: init(6u, 4u, 0u)");
#endif
    (void)(m18_tableX5FoperationsX2E7Export6_active(&instance_7, 0u));
    printOK("WAST line 364: active(0u)");
    (void)(m18_tableX5FoperationsX2E7Export8_declared(&instance_7, 0u));
    printOK("WAST line 365: declared(0u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export6_active(&instance_7, 1u), "WAST line 366: active(1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export8_declared(&instance_7, 1u), "WAST line 367: declared(1u)");
#endif
    (void)(m18_tableX5FoperationsX2E7Export4_init(&instance_7, 1u, 0u, 3u));
    printOK("WAST line 368: init(1u, 0u, 3u)");
    (void)(m18_tableX5FoperationsX2E7Export4_init(&instance_7, 3u, 0u, 3u));
    printOK("WAST line 369: init(3u, 0u, 3u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 1u)) == testExternRef(0u), 1u, "WAST line 370: get(1u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 2u)) == wasmNullExternRef, 1u, "WAST line 371: get(2u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 3u)) == testExternRef(0u), 1u, "WAST line 372: get(3u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 4u)) == wasmNullExternRef, 1u, "WAST line 373: get(4u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 5u)) == testExternRef(0u), 1u, "WAST line 374: get(5u)");
    (void)(m18_tableX5FoperationsX2E7Export4_drop(&instance_7));
    printOK("WAST line 375: drop()");
    (void)(m18_tableX5FoperationsX2E7Export4_drop(&instance_7));
    printOK("WAST line 376: drop()");
    (void)(m18_tableX5FoperationsX2E7Export4_init(&instance_7, 6u, 0u, 0u));
    printOK("WAST line 377: init(6u, 0u, 0u)");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_init(&instance_7, 6u, 1u, 0u), "WAST line 378: init(6u, 1u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m18_tableX5FoperationsX2E7Export4_init(&instance_7, 0u, 0u, 1u), "WAST line 379: init(0u, 0u, 1u)");
#endif
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 0u)) == testExternRef(1u), 1u, "WAST line 380: get(0u)");
    assertEqualU32(
        m18_tableX5FoperationsX2E7Export4_grow(&instance_7, testExternRef(10u), 0u),
        6u,
        "WAST line 381: grow(testExternRef(10u), 0u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E7Export4_grow(&instance_7, testExternRef(10u), 2u),
        6u,
        "WAST line 382: grow(testExternRef(10u), 2u)"
    );
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 6u)) == testExternRef(10u), 1u, "WAST line 383: get(6u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 7u)) == testExternRef(10u), 1u, "WAST line 384: get(7u)");
    assertEqualU32(
        m18_tableX5FoperationsX2E7Export4_grow(&instance_7, wasmNullExternRef, 1u),
        4294967295u,
        "WAST line 385: grow(wasmNullExternRef, 1u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E7Export4_grow(&instance_7, wasmNullExternRef, 4294967295u),
        4294967295u,
        "WAST line 386: grow(wasmNullExternRef, 4294967295u)"
    );
    assertEqualU32(
        m18_tableX5FoperationsX2E7Export4_size(&instance_7),
        8u,
        "WAST line 387: size()"
    );
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 7u)) == testExternRef(10u), 1u, "WAST line 388: get(7u)");
    (void)(m18_tableX5FoperationsX2E7Export4_fill(&instance_7, 6u, wasmNullExternRef, 2u));
    printOK("WAST line 389: fill(6u, wasmNullExternRef, 2u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 7u)) == wasmNullExternRef, 1u, "WAST line 390: get(7u)");
    m18_tableX5FoperationsX2E8Instantiate(&instance_8, resolveTestImports);
    printStart("table_operations.8.wasm");
    bindTestImport("externalias", "table", (void*)m18_tableX5FoperationsX2E8Export5_table(&instance_8));
    bindTestImport("externalias", "host", (void*)m18_tableX5FoperationsX2E8Export4_host(&instance_8));
    {
        struct w2c2_result_er result;
        result = m18_tableX5FoperationsX2E8Export9_roundtrip(&instance_8, testExternRef(0u));
        assertEqualU32((result.v0) == testExternRef(0u), 1u, "WAST line 408: roundtrip(testExternRef(0u)) result 0");
        assertEqualU32((result.v1).func != NULL, 1u, "WAST line 408: roundtrip(testExternRef(0u)) result 1");
    }
    assertEqualU32((m18_tableX5FoperationsX2E8Export5_alias(&instance_8, testExternRef(20u))) == testExternRef(20u), 1u, "WAST line 409: alias(testExternRef(20u))");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 0u)) == testExternRef(0u), 1u, "WAST line 410: get(0u)");
    assertEqualU32((m18_tableX5FoperationsX2E7Export3_get(&instance_7, 2u)) == testExternRef(20u), 1u, "WAST line 411: get(2u)");
    m18_tableX5FoperationsX2E9Instantiate(&instance_9, resolveTestImports);
    printStart("table_operations.9.wasm");
    assertEqualU32((m18_tableX5FoperationsX2E9Export3_get(&instance_9)) == testExternRef(20u), 1u, "WAST line 417: get()");
    assertEqualU32((m18_tableX5FoperationsX2E9Export4_host(&instance_9)) == testExternRef(0u), 1u, "WAST line 418: host()");
    m18_tableX5FoperationsX2E9FreeInstance(&instance_9);
    m18_tableX5FoperationsX2E8FreeInstance(&instance_8);
    m18_tableX5FoperationsX2E7FreeInstance(&instance_7);
    m18_tableX5FoperationsX2E6FreeInstance(&instance_6);
    m18_tableX5FoperationsX2E5FreeInstance(&instance_5);
    m18_tableX5FoperationsX2E4FreeInstance(&instance_4);
    m18_tableX5FoperationsX2E3FreeInstance(&instance_3);
    m18_tableX5FoperationsX2E2FreeInstance(&instance_2);
    m18_tableX5FoperationsX2E1FreeInstance(&instance_1);
    m18_tableX5FoperationsX2E0FreeInstance(&instance_0);
}
