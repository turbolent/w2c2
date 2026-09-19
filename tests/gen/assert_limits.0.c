
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_limits.0.h"

void test() {
    limits0Instance instance;
    limits0Instantiate(&instance, resolveTestImports);
    printStart("limits.0.wasm");
    assertEqualU32(
        limits0_size(&instance),
        0u,
        "size()"
    );
    assertEqualU32(
        limits0_grow(&instance, 0u),
        0u,
        "grow(0u)"
    );
    assertEqualU32(
        limits0_grow(&instance, 1u),
        4294967295u,
        "grow(1u)"
    );
    assertEqualU32(
        limits0_grow(&instance, 4294967295u),
        4294967295u,
        "grow(4294967295u)"
    );
    assertEqualU32(
        limits0_size(&instance),
        0u,
        "size()"
    );
}
