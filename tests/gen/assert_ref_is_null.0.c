#include "test.h"
#include "test_ref_is_null.0.h"

void test(void) {
    static m13_refX5FisX5FnullX2E0Instance instance;
    m13_refX5FisX5FnullX2E0Instantiate(&instance, resolveTestImports);
    printStart("ref_is_null.0.wasm");
    assertEqualU32(
        m13_refX5FisX5FnullX2E0Export7_funcref(&instance, wasmNullFuncRef),
        1u,
        "funcref(wasmNullFuncRef)"
    );
    assertEqualU32(
        m13_refX5FisX5FnullX2E0Export9_externref(&instance, wasmNullExternRef),
        1u,
        "externref(wasmNullExternRef)"
    );
    assertEqualU32(
        m13_refX5FisX5FnullX2E0Export9_externref(&instance, testExternRef(1u)),
        0u,
        "externref(testExternRef(1u))"
    );
    (void)(m13_refX5FisX5FnullX2E0Export4_init(&instance, testExternRef(0u)));
    printOK("init(testExternRef(0u))");
    assertEqualU32(
        m13_refX5FisX5FnullX2E0Export12_funcrefX2Delem(&instance, 0u),
        1u,
        "funcref-elem(0u)"
    );
    assertEqualU32(
        m13_refX5FisX5FnullX2E0Export14_externrefX2Delem(&instance, 0u),
        1u,
        "externref-elem(0u)"
    );
    assertEqualU32(
        m13_refX5FisX5FnullX2E0Export12_funcrefX2Delem(&instance, 1u),
        0u,
        "funcref-elem(1u)"
    );
    assertEqualU32(
        m13_refX5FisX5FnullX2E0Export14_externrefX2Delem(&instance, 1u),
        0u,
        "externref-elem(1u)"
    );
    (void)(m13_refX5FisX5FnullX2E0Export6_deinit(&instance));
    printOK("deinit()");
    assertEqualU32(
        m13_refX5FisX5FnullX2E0Export12_funcrefX2Delem(&instance, 0u),
        1u,
        "funcref-elem(0u)"
    );
    assertEqualU32(
        m13_refX5FisX5FnullX2E0Export14_externrefX2Delem(&instance, 0u),
        1u,
        "externref-elem(0u)"
    );
    assertEqualU32(
        m13_refX5FisX5FnullX2E0Export12_funcrefX2Delem(&instance, 1u),
        1u,
        "funcref-elem(1u)"
    );
    assertEqualU32(
        m13_refX5FisX5FnullX2E0Export14_externrefX2Delem(&instance, 1u),
        1u,
        "externref-elem(1u)"
    );
    m13_refX5FisX5FnullX2E0FreeInstance(&instance);
}
