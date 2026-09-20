
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_start.3.h"

void test() {
    m7_startX2E3Instance instance;
    m7_startX2E3Instantiate(&instance, resolveTestImports);
    printStart("start.3.wasm");
    assertEqualU32(
        m7_startX2E3Export3_get(&instance),
        68u,
        "get()"
    );
    m7_startX2E3Export3_inc(&instance);
    printOK("inc()");
    assertEqualU32(
        m7_startX2E3Export3_get(&instance),
        69u,
        "get()"
    );
    m7_startX2E3Export3_inc(&instance);
    printOK("inc()");
    assertEqualU32(
        m7_startX2E3Export3_get(&instance),
        70u,
        "get()"
    );
}
