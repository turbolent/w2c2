
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_redundancy.0.h"

void test() {
    memoryredundancy0Instance instance;
    memoryredundancy0Instantiate(&instance, resolveTestImports);
    printStart("memory_redundancy.0.wasm");
    assertEqualU32(
        memoryredundancy0_test_store_to_load(&instance),
        128u,
        "test_store_to_load()"
    );
    memoryredundancy0_zero_everything(&instance);
    printOK("zero_everything()");
    assertEqualU32(
        memoryredundancy0_test_redundant_load(&instance),
        128u,
        "test_redundant_load()"
    );
    memoryredundancy0_zero_everything(&instance);
    printOK("zero_everything()");
    assertEqualF32(
        memoryredundancy0_test_dead_store(&instance),
        4.90454462513686e-44,
        "test_dead_store()"
    );
    memoryredundancy0_zero_everything(&instance);
    printOK("zero_everything()");
    assertEqualU32(
        memoryredundancy0_malloc_aliasing(&instance),
        43u,
        "malloc_aliasing()"
    );
}
