
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_import_data.1.h"

void test() {
    m20_memoryX5FimportX5FdataX2E1Instance instance;
    m20_memoryX5FimportX5FdataX2E1Instantiate(&instance, resolveTestImports);
    printStart("memory_import_data.1.wasm");
    assertEqualU32(
        m20_memoryX5FimportX5FdataX2E1Export8_observed(&instance),
        1297301847u,
        "observed()"
    );
}
