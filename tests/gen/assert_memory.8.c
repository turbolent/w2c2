
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory.8.h"

void test() {
    memory8Instance instance;
    memory8Instantiate(&instance, resolveTestImports);
    printStart("memory.8.wasm");
    assertEqualU32(
        memory8_memsize(&instance),
        0u,
        "memsize()"
    );
}
