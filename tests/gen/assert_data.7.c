
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.7.h"

void test() {
    m6_dataX2E7Instance instance;
    m6_dataX2E7Instantiate(&instance, resolveTestImports);
    printStart("data.7.wasm");
}
