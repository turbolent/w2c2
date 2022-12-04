
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.44.h"

void test() {
    elem44Instance instance;
    elem44Instantiate(&instance, resolveTestImports);
    printStart("elem.44.wasm");
    assertEqualU32(
        elem44_callX2DoverwrittenX2Delement(&instance),
        66u,
        "call-overwritten-element()"
    );
}
