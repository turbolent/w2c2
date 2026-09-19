
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_limits.1.h"

void test() {
    limits1Instance instance;
    limits1Instantiate(&instance, resolveTestImports);
    printStart("limits.1.wasm");
    assertEqualU32(
        limits1_size(&instance),
        0u,
        "size()"
    );
    assertEqualU32(
        limits1_grow(&instance, 0u),
        0u,
        "grow(0u)"
    );
    assertEqualU32(
        limits1_grow(&instance, 1u),
        4294967295u,
        "grow(1u)"
    );
    assertEqualU32(
        limits1_grow(&instance, 4294967295u),
        4294967295u,
        "grow(4294967295u)"
    );
    assertEqualU32(
        limits1_size(&instance),
        0u,
        "size()"
    );
}
