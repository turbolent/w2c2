
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_bulk.0.h"

void test() {
    bulk0Instance instance;
    bulk0Instantiate(&instance, resolveTestImports);
    printStart("bulk.0.wasm");
}
