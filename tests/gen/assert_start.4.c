
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_start.4.h"

void test() {
    start4Instance instance;
    start4Instantiate(&instance, resolveTestImports);
    printStart("start.4.wasm");
    assertEqualU32(
        start4_get(&instance),
        68u,
        "get()"
    );
    start4_inc(&instance);
    printOK("inc()");
    assertEqualU32(
        start4_get(&instance),
        69u,
        "get()"
    );
    start4_inc(&instance);
    printOK("inc()");
    assertEqualU32(
        start4_get(&instance),
        70u,
        "get()"
    );
}
