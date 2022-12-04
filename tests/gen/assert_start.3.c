
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_start.3.h"

void test() {
    start3Instance instance;
    start3Instantiate(&instance, resolveTestImports);
    printStart("start.3.wasm");
    assertEqualU32(
        start3_get(&instance),
        68u,
        "get()"
    );
    start3_inc(&instance);
    printOK("inc()");
    assertEqualU32(
        start3_get(&instance),
        69u,
        "get()"
    );
    start3_inc(&instance);
    printOK("inc()");
    assertEqualU32(
        start3_get(&instance),
        70u,
        "get()"
    );
}
