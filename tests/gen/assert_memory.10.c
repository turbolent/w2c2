
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.10.h"

void test() {
    memory10Instance instance;
    memory10Instantiate(&instance, resolveTestImports);
    printStart("memory.10.wasm");
    assertEqualU32(
        memory10_memsize(&instance),
        1u,
        "memsize()"
    );
}
