
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.8.h"

void test() {
    m6_elemX2E8Instance instance;
    m6_elemX2E8Instantiate(&instance, resolveTestImports);
    printStart("elem.8.wasm");
    assertEqualU32(
        m6_elemX2E8Export6_callX2D7(&instance),
        65u,
        "call-7()"
    );
    assertEqualU32(
        m6_elemX2E8Export6_callX2D9(&instance),
        66u,
        "call-9()"
    );
}
