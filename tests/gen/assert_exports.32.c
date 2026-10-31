#include "test.h"
#include "test_exports.32.h"

void test(void) {
    static m10_exportsX2E32Instance instance;
    m10_exportsX2E32Instantiate(&instance, resolveTestImports);
    printStart("exports.32.wasm");
    assertEqualU32(
        *m10_exportsX2E32Export1_e(&instance),
        42u,
        "get e"
    );
    assertEqualU32(
        *m10_exportsX2E32Export1_e(&instance),
        42u,
        "get e"
    );
    assertEqualU32(
        *m10_exportsX2E32Export1_e(&instance),
        42u,
        "get e"
    );
    m10_exportsX2E32FreeInstance(&instance);
}
