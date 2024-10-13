
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.8.h"

void test() {
    elem8Instance instance;
    elem8Instantiate(&instance, resolveTestImports);
    printStart("elem.8.wasm");
    assertEqualU32(
        elem8_callX2D7(&instance),
        65u,
        "call-7()"
    );
    assertEqualU32(
        elem8_callX2D9(&instance),
        66u,
        "call-9()"
    );
}
