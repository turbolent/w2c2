
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_redundancy.0.h"

void test() {
    m19_memoryX5FredundancyX2E0Instance instance;
    m19_memoryX5FredundancyX2E0Instantiate(&instance, resolveTestImports);
    printStart("memory_redundancy.0.wasm");
    assertEqualU32(
        m19_memoryX5FredundancyX2E0Export18_testX5FstoreX5FtoX5Fload(&instance),
        128u,
        "test_store_to_load()"
    );
    m19_memoryX5FredundancyX2E0Export15_zeroX5Feverything(&instance);
    printOK("zero_everything()");
    assertEqualU32(
        m19_memoryX5FredundancyX2E0Export19_testX5FredundantX5Fload(&instance),
        128u,
        "test_redundant_load()"
    );
    m19_memoryX5FredundancyX2E0Export15_zeroX5Feverything(&instance);
    printOK("zero_everything()");
    assertEqualU32(
        i32_reinterpret_f32(m19_memoryX5FredundancyX2E0Export15_testX5FdeadX5Fstore(&instance)),
        35u,
        "test_dead_store()"
    );
    m19_memoryX5FredundancyX2E0Export15_zeroX5Feverything(&instance);
    printOK("zero_everything()");
    assertEqualU32(
        m19_memoryX5FredundancyX2E0Export15_mallocX5Faliasing(&instance),
        43u,
        "malloc_aliasing()"
    );
}
