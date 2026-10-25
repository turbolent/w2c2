
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.48.h"

void test() {
    m7_elemX2E48Instance instance;
    m7_elemX2E48Instantiate(&instance, resolveTestImports);
    printStart("elem.48.wasm");
    assertEqualU32(
        m7_elemX2E48Export24_callX2DoverwrittenX2Delement(&instance),
        66u,
        "call-overwritten-element()"
    );
}
