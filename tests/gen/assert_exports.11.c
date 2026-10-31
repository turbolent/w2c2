#include "test.h"
#include "test_exports.11.h"

void test(void) {
    static m10_exportsX2E11Instance instance;
    m10_exportsX2E11Instantiate(&instance, resolveTestImports);
    printStart("exports.11.wasm");
    assertEqualU32(
        m10_exportsX2E11Export1_e(&instance, 42u),
        43u,
        "e(42u)"
    );
    assertEqualU32(
        m10_exportsX2E11Export1_e(&instance, 42u),
        43u,
        "e(42u)"
    );
    assertEqualU32(
        m10_exportsX2E11Export1_e(&instance, 42u),
        43u,
        "e(42u)"
    );
    m10_exportsX2E11FreeInstance(&instance);
}
