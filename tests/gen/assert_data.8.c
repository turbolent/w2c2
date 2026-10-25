
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.8.h"

void test() {
    m6_dataX2E8Instance instance;
    m6_dataX2E8Instantiate(&instance, resolveTestImports);
    printStart("data.8.wasm");
}
