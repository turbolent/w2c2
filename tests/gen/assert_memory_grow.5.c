
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_grow.5.h"

void test() {
    memorygrow5Instance instance;
    memorygrow5Instantiate(&instance, resolveTestImports);
    printStart("memory_grow.5.wasm");
    assertEqualU32(
        memorygrow5_grow(&instance),
        1u,
        "grow()"
    );
}
