
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.47.h"

void test() {
    m7_elemX2E47Instance instance;
    m7_elemX2E47Instantiate(&instance, resolveTestImports);
    printStart("elem.47.wasm");
    assertEqualU32(
        m7_elemX2E47Export16_callX2Doverwritten(&instance),
        66u,
        "call-overwritten()"
    );
}
