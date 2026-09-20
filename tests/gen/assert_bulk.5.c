
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_bulk.5.h"

void test() {
    m6_bulkX2E5Instance instance;
    m6_bulkX2E5Instantiate(&instance, resolveTestImports);
    printStart("bulk.5.wasm");
}
