
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.2.h"

void test() {
    m6_dataX2E2Instance instance;
    m6_dataX2E2Instantiate(&instance, resolveTestImports);
    printStart("data.2.wasm");
}
