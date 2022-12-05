
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_grow.2.h"

void test() {
    memorygrow2Instance instance;
    memorygrow2Instantiate(&instance, resolveTestImports);
    printStart("memory_grow.2.wasm");
    assertEqualU32(
        memorygrow2_grow(&instance, 0u),
        0u,
        "grow(0u)"
    );
    assertEqualU32(
        memorygrow2_grow(&instance, 1u),
        0u,
        "grow(1u)"
    );
    assertEqualU32(
        memorygrow2_grow(&instance, 1u),
        1u,
        "grow(1u)"
    );
    assertEqualU32(
        memorygrow2_grow(&instance, 2u),
        2u,
        "grow(2u)"
    );
    assertEqualU32(
        memorygrow2_grow(&instance, 6u),
        4u,
        "grow(6u)"
    );
    assertEqualU32(
        memorygrow2_grow(&instance, 0u),
        10u,
        "grow(0u)"
    );
    assertEqualU32(
        memorygrow2_grow(&instance, 1u),
        4294967295u,
        "grow(1u)"
    );
    assertEqualU32(
        memorygrow2_grow(&instance, 65536u),
        4294967295u,
        "grow(65536u)"
    );
}
