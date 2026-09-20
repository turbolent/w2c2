
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.11.h"

void test() {
    m10_exportsX2E11Instance instance;
    m10_exportsX2E11Instantiate(&instance, resolveTestImports);
    printStart("exports.11.wasm");
    assertEqualU32(
        m10_exportsX2E11Export1_a(&instance),
        42u,
        "a()"
    );
    assertEqualU32(
        m10_exportsX2E11Export1_b(&instance),
        42u,
        "b()"
    );
    assertEqualU32(
        m10_exportsX2E11Export1_c(&instance),
        42u,
        "c()"
    );
}
