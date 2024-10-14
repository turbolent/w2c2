
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.34.h"

void test() {
    memory34Instance instance;
    memory34Instantiate(&instance, resolveTestImports);
    printStart("memory.34.wasm");
    assertEqualU32(
        memory34_load(&instance, 0u),
        0u,
        "load(0u)"
    );
    assertEqualU32(
        memory34_load(&instance, 10000u),
        0u,
        "load(10000u)"
    );
    assertEqualU32(
        memory34_load(&instance, 20000u),
        0u,
        "load(20000u)"
    );
    assertEqualU32(
        memory34_load(&instance, 30000u),
        0u,
        "load(30000u)"
    );
    assertEqualU32(
        memory34_load(&instance, 40000u),
        0u,
        "load(40000u)"
    );
    assertEqualU32(
        memory34_load(&instance, 50000u),
        0u,
        "load(50000u)"
    );
    assertEqualU32(
        memory34_load(&instance, 60000u),
        0u,
        "load(60000u)"
    );
    assertEqualU32(
        memory34_load(&instance, 65535u),
        0u,
        "load(65535u)"
    );
}
