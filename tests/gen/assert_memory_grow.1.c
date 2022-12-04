
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_grow.1.h"

void test() {
    memorygrow1Instance instance;
    memorygrow1Instantiate(&instance, resolveTestImports);
    printStart("memory_grow.1.wasm");
    assertEqualU32(
        memorygrow1_grow(&instance, 0u),
        0u,
        "grow(0u)"
    );
    assertEqualU32(
        memorygrow1_grow(&instance, 1u),
        0u,
        "grow(1u)"
    );
    assertEqualU32(
        memorygrow1_grow(&instance, 0u),
        1u,
        "grow(0u)"
    );
    assertEqualU32(
        memorygrow1_grow(&instance, 2u),
        1u,
        "grow(2u)"
    );
    assertEqualU32(
        memorygrow1_grow(&instance, 800u),
        3u,
        "grow(800u)"
    );
    assertEqualU32(
        memorygrow1_grow(&instance, 65536u),
        4294967295u,
        "grow(65536u)"
    );
    assertEqualU32(
        memorygrow1_grow(&instance, 64736u),
        4294967295u,
        "grow(64736u)"
    );
    assertEqualU32(
        memorygrow1_grow(&instance, 1u),
        803u,
        "grow(1u)"
    );
}
