
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_bulk.3.h"

void test() {
    bulk3Instance instance;
    bulk3Instantiate(&instance, resolveTestImports);
    printStart("bulk.3.wasm");
    bulk3_init(&instance, 0u, 1u, 2u);
    printOK("init(0u, 1u, 2u)");
    assertEqualU32(
        bulk3_load8_u(&instance, 0u),
        187u,
        "load8_u(0u)"
    );
    assertEqualU32(
        bulk3_load8_u(&instance, 1u),
        204u,
        "load8_u(1u)"
    );
    assertEqualU32(
        bulk3_load8_u(&instance, 2u),
        0u,
        "load8_u(2u)"
    );
    bulk3_init(&instance, 65532u, 0u, 4u);
    printOK("init(65532u, 0u, 4u)");
    assertEqualU32(
        bulk3_load8_u(&instance, 65534u),
        204u,
        "load8_u(65534u)"
    );
    assertEqualU32(
        bulk3_load8_u(&instance, 65535u),
        221u,
        "load8_u(65535u)"
    );
    bulk3_init(&instance, 65536u, 0u, 0u);
    printOK("init(65536u, 0u, 0u)");
    bulk3_init(&instance, 0u, 4u, 0u);
    printOK("init(0u, 4u, 0u)");
}
