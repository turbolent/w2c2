#include "test.h"
#include "test_ref_func.0.h"
#include "test_ref_func.1.h"
#include "test_ref_func.3.h"

static m10_refX5FfuncX2E0Instance instance_0;
static m10_refX5FfuncX2E1Instance instance_1;
static m10_refX5FfuncX2E3Instance instance_2;

U32 m10_refX5FfuncX2E1Import1_M1_f(wasmModuleInstance* instance, U32 p0) {
    (void)instance;
    return m10_refX5FfuncX2E0Export1_f(&instance_0, p0);
}
void test(void) {
    m10_refX5FfuncX2E0Instantiate(&instance_0, resolveTestImports);
    printStart("ref_func.0.wasm");
    m10_refX5FfuncX2E1Instantiate(&instance_1, resolveTestImports);
    printStart("ref_func.1.wasm");
    assertEqualU32(
        m10_refX5FfuncX2E1Export9_isX5FnullX2Df(&instance_1),
        0u,
        "WAST line 56: is_null-f()"
    );
    assertEqualU32(
        m10_refX5FfuncX2E1Export9_isX5FnullX2Dg(&instance_1),
        0u,
        "WAST line 57: is_null-g()"
    );
    assertEqualU32(
        m10_refX5FfuncX2E1Export9_isX5FnullX2Dv(&instance_1),
        0u,
        "WAST line 58: is_null-v()"
    );
    assertEqualU32(
        m10_refX5FfuncX2E1Export6_callX2Df(&instance_1, 4u),
        4u,
        "WAST line 60: call-f(4u)"
    );
    assertEqualU32(
        m10_refX5FfuncX2E1Export6_callX2Dg(&instance_1, 4u),
        5u,
        "WAST line 61: call-g(4u)"
    );
    assertEqualU32(
        m10_refX5FfuncX2E1Export6_callX2Dv(&instance_1, 4u),
        4u,
        "WAST line 62: call-v(4u)"
    );
    (void)(m10_refX5FfuncX2E1Export5_setX2Dg(&instance_1));
    printOK("WAST line 63: set-g()");
    assertEqualU32(
        m10_refX5FfuncX2E1Export6_callX2Dv(&instance_1, 4u),
        5u,
        "WAST line 64: call-v(4u)"
    );
    (void)(m10_refX5FfuncX2E1Export5_setX2Df(&instance_1));
    printOK("WAST line 65: set-f()");
    assertEqualU32(
        m10_refX5FfuncX2E1Export6_callX2Dv(&instance_1, 4u),
        4u,
        "WAST line 66: call-v(4u)"
    );
    m10_refX5FfuncX2E3Instantiate(&instance_2, resolveTestImports);
    printStart("ref_func.3.wasm");
    m10_refX5FfuncX2E3FreeInstance(&instance_2);
    m10_refX5FfuncX2E1FreeInstance(&instance_1);
    m10_refX5FfuncX2E0FreeInstance(&instance_0);
}
