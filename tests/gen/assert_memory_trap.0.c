
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_trap.0.h"

void test() {
    memorytrap0Instance instance;
    memorytrap0Instantiate(&instance, resolveTestImports);
    printStart("memory_trap.0.wasm");
    memorytrap0_store(&instance, 4294967292u, 42u);
    assertEqualU32(
        memorytrap0_load(&instance, 4294967292u),
        42u,
        "load(4294967292u)"
    );
    assertEqualU32(
        memorytrap0_memoryX2Egrow(&instance, 65537u),
        4294967295u,
        "memory.grow(65537u)"
    );
}
