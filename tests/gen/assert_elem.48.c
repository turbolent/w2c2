
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.48.h"

void test() {
    elem48Instance instance;
    elem48Instantiate(&instance, resolveTestImports);
    printStart("elem.48.wasm");
    assertEqualU32(
        elem48_callX2DoverwrittenX2Delement(&instance),
        66u,
        "call-overwritten-element()"
    );
}
