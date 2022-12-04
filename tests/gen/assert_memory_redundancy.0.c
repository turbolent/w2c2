
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_redundancy.0.h"

void test() {
    memoryredundancy0Instance instance;
    memoryredundancy0Instantiate(&instance, resolveTestImports);
    printStart("memory_redundancy.0.wasm");
    assertEqualU32(
        memoryredundancy0_testX5FstoreX5FtoX5Fload(&instance),
        128u,
        "test_store_to_load()"
    );
    memoryredundancy0_zeroX5Feverything(&instance);
    printOK("zero_everything()");
    assertEqualU32(
        memoryredundancy0_testX5FredundantX5Fload(&instance),
        128u,
        "test_redundant_load()"
    );
    memoryredundancy0_zeroX5Feverything(&instance);
    printOK("zero_everything()");
    assertEqualF32(
        memoryredundancy0_testX5FdeadX5Fstore(&instance),
        4.90454462513686e-44,
        "test_dead_store()"
    );
    memoryredundancy0_zeroX5Feverything(&instance);
    printOK("zero_everything()");
    assertEqualU32(
        memoryredundancy0_mallocX5Faliasing(&instance),
        43u,
        "malloc_aliasing()"
    );
}
