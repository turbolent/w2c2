
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.47.h"

void test() {
    elem47Instance instance;
    elem47Instantiate(&instance, resolveTestImports);
    printStart("elem.47.wasm");
    assertEqualU32(
        elem47_callX2Doverwritten(&instance),
        66u,
        "call-overwritten()"
    );
}
