
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_trap.0.h"

void test() {
    m13_memoryX5FtrapX2E0Instance instance;
    m13_memoryX5FtrapX2E0Instantiate(&instance, resolveTestImports);
    printStart("memory_trap.0.wasm");
    m13_memoryX5FtrapX2E0Export5_store(&instance, 4294967292u, 42u);
    assertEqualU32(
        m13_memoryX5FtrapX2E0Export4_load(&instance, 4294967292u),
        42u,
        "load(4294967292u)"
    );
    assertEqualU32(
        m13_memoryX5FtrapX2E0Export11_memoryX2Egrow(&instance, 65537u),
        4294967295u,
        "memory.grow(65537u)"
    );
}
