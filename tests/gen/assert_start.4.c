
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_start.4.h"

void test() {
    m7_startX2E4Instance instance;
    m7_startX2E4Instantiate(&instance, resolveTestImports);
    printStart("start.4.wasm");
    assertEqualU32(
        m7_startX2E4Export3_get(&instance),
        68u,
        "get()"
    );
    m7_startX2E4Export3_inc(&instance);
    printOK("inc()");
    assertEqualU32(
        m7_startX2E4Export3_get(&instance),
        69u,
        "get()"
    );
    m7_startX2E4Export3_inc(&instance);
    printOK("inc()");
    assertEqualU32(
        m7_startX2E4Export3_get(&instance),
        70u,
        "get()"
    );
}
