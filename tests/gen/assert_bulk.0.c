
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_bulk.0.h"

void test() {
    m6_bulkX2E0Instance instance;
    m6_bulkX2E0Instantiate(&instance, resolveTestImports);
    printStart("bulk.0.wasm");
}
