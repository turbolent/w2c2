
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_bulk.1.h"

void test() {
    bulk1Instance instance;
    bulk1Instantiate(&instance, resolveTestImports);
    printStart("bulk.1.wasm");
    bulk1_fill(&instance, 1u, 255u, 3u);
    printOK("fill(1u, 255u, 3u)");
    assertEqualU32(
        bulk1_load8_u(&instance, 0u),
        0u,
        "load8_u(0u)"
    );
    assertEqualU32(
        bulk1_load8_u(&instance, 1u),
        255u,
        "load8_u(1u)"
    );
    assertEqualU32(
        bulk1_load8_u(&instance, 2u),
        255u,
        "load8_u(2u)"
    );
    assertEqualU32(
        bulk1_load8_u(&instance, 3u),
        255u,
        "load8_u(3u)"
    );
    assertEqualU32(
        bulk1_load8_u(&instance, 4u),
        0u,
        "load8_u(4u)"
    );
    bulk1_fill(&instance, 0u, 48042u, 2u);
    printOK("fill(0u, 48042u, 2u)");
    assertEqualU32(
        bulk1_load8_u(&instance, 0u),
        170u,
        "load8_u(0u)"
    );
    assertEqualU32(
        bulk1_load8_u(&instance, 1u),
        170u,
        "load8_u(1u)"
    );
    bulk1_fill(&instance, 0u, 0u, 65536u);
    printOK("fill(0u, 0u, 65536u)");
    assertEqualU32(
        bulk1_load8_u(&instance, 65280u),
        0u,
        "load8_u(65280u)"
    );
    assertEqualU32(
        bulk1_load8_u(&instance, 65535u),
        0u,
        "load8_u(65535u)"
    );
    bulk1_fill(&instance, 65536u, 0u, 0u);
    printOK("fill(65536u, 0u, 0u)");
}
