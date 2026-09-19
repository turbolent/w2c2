
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_import_data.0.h"

void test() {
    memoryimportdata0Instance instance;
    memoryimportdata0Instantiate(&instance, resolveTestImports);
    printStart("memory_import_data.0.wasm");
    assertEqualU32(
        memoryimportdata0_observed(&instance),
        1148811329u,
        "observed()"
    );
    assertEqualU32(
        memoryimportdata0_load(&instance, 4u),
        0u,
        "load(4u)"
    );
    assertEqualU32(
        memoryimportdata0_load(&instance, 5u),
        255u,
        "load(5u)"
    );
    assertEqualU32(
        memoryimportdata0_load(&instance, 6u),
        127u,
        "load(6u)"
    );
    assertEqualU32(
        memoryimportdata0_load(&instance, 7u),
        128u,
        "load(7u)"
    );
    assertEqualU32(
        memoryimportdata0_load(&instance, 666u),
        65u,
        "load(666u)"
    );
    assertEqualU32(
        memoryimportdata0_load(&instance, 667u),
        120u,
        "load(667u)"
    );
    assertEqualU32(
        memoryimportdata0_load(&instance, 668u),
        121u,
        "load(668u)"
    );
    assertEqualU32(
        memoryimportdata0_load(&instance, 669u),
        68u,
        "load(669u)"
    );
}
