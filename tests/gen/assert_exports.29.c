
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.29.h"

void test() {
    m10_exportsX2E29Instance instance;
    m10_exportsX2E29Instantiate(&instance, resolveTestImports);
    printStart("exports.29.wasm");
    assertEqualU32(
        *m10_exportsX2E29Export1_e(&instance),
        42u,
        "get e"
    );
    assertEqualU32(
        *m10_exportsX2E29Export1_e(&instance),
        42u,
        "get e"
    );
    assertEqualU32(
        *m10_exportsX2E29Export1_e(&instance),
        42u,
        "get e"
    );
}
