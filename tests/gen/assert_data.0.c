
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.0.h"

void test() {
    m6_dataX2E0Instance instance;
    m6_dataX2E0Instantiate(&instance, resolveTestImports);
    printStart("data.0.wasm");
}
