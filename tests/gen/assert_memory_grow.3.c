
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_grow.3.h"

void test() {
    memorygrow3Instance instance;
    memorygrow3Instantiate(&instance, resolveTestImports);
    printStart("memory_grow.3.wasm");
    assertEqualU32(
        memorygrow3_checkX2DmemoryX2Dzero(&instance, 0u, 65535u),
        0u,
        "check-memory-zero(0u, 65535u)"
    );
    assertEqualU32(
        memorygrow3_grow(&instance, 1u),
        1u,
        "grow(1u)"
    );
    assertEqualU32(
        memorygrow3_checkX2DmemoryX2Dzero(&instance, 65536u, 131071u),
        0u,
        "check-memory-zero(65536u, 131071u)"
    );
    assertEqualU32(
        memorygrow3_grow(&instance, 1u),
        2u,
        "grow(1u)"
    );
    assertEqualU32(
        memorygrow3_checkX2DmemoryX2Dzero(&instance, 131072u, 196607u),
        0u,
        "check-memory-zero(131072u, 196607u)"
    );
    assertEqualU32(
        memorygrow3_grow(&instance, 1u),
        3u,
        "grow(1u)"
    );
    assertEqualU32(
        memorygrow3_checkX2DmemoryX2Dzero(&instance, 196608u, 262143u),
        0u,
        "check-memory-zero(196608u, 262143u)"
    );
    assertEqualU32(
        memorygrow3_grow(&instance, 1u),
        4u,
        "grow(1u)"
    );
    assertEqualU32(
        memorygrow3_checkX2DmemoryX2Dzero(&instance, 262144u, 327679u),
        0u,
        "check-memory-zero(262144u, 327679u)"
    );
    assertEqualU32(
        memorygrow3_grow(&instance, 1u),
        5u,
        "grow(1u)"
    );
    assertEqualU32(
        memorygrow3_checkX2DmemoryX2Dzero(&instance, 327680u, 393215u),
        0u,
        "check-memory-zero(327680u, 393215u)"
    );
}
