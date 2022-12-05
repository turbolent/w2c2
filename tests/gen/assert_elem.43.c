
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_elem.43.h"

void test() {
    elem43Instance instance;
    elem43Instantiate(&instance, resolveTestImports);
    printStart("elem.43.wasm");
    assertEqualU32(
        elem43_callX2Doverwritten(&instance),
        66u,
        "call-overwritten()"
    );
}
