#include "test.h"
#include "test_exports.14.h"

void test(void) {
    static m10_exportsX2E14Instance instance;
    m10_exportsX2E14Instantiate(&instance, resolveTestImports);
    printStart("exports.14.wasm");
    assertEqualU32(
        m10_exportsX2E14Export1_a(&instance),
        42u,
        "a()"
    );
    assertEqualU32(
        m10_exportsX2E14Export1_b(&instance),
        42u,
        "b()"
    );
    assertEqualU32(
        m10_exportsX2E14Export1_c(&instance),
        42u,
        "c()"
    );
    m10_exportsX2E14FreeInstance(&instance);
}
