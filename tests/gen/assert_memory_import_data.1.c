
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_import_data.1.h"

void test() {
    memoryimportdata1Instance instance;
    memoryimportdata1Instantiate(&instance, resolveTestImports);
    printStart("memory_import_data.1.wasm");
    assertEqualU32(
        memoryimportdata1_observed(&instance),
        1297301847u,
        "observed()"
    );
}
