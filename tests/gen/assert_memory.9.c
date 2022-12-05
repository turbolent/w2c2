
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.9.h"

void test() {
    memory9Instance instance;
    memory9Instantiate(&instance, resolveTestImports);
    printStart("memory.9.wasm");
    assertEqualU32(
        memory9_memsize(&instance),
        0u,
        "memsize()"
    );
}
