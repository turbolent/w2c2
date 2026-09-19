
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_import_data.2.h"

void test() {
    memoryimportdata2Instance instance;
    memoryimportdata2Instantiate(&instance, resolveTestImports);
    printStart("memory_import_data.2.wasm");
    assertEqualU32(
        memoryimportdata2_observed(&instance),
        1297301847u,
        "observed()"
    );
}
