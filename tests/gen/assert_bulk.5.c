
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_bulk.5.h"

void test() {
    bulk5Instance instance;
    bulk5Instantiate(&instance, resolveTestImports);
    printStart("bulk.5.wasm");
}
