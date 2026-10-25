
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_bulk.6.h"

void test() {
    m6_bulkX2E6Instance instance;
    m6_bulkX2E6Instantiate(&instance, resolveTestImports);
    printStart("bulk.6.wasm");
}
