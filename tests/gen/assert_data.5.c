
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.5.h"

void test() {
    m6_dataX2E5Instance instance;
    m6_dataX2E5Instantiate(&instance, resolveTestImports);
    printStart("data.5.wasm");
}
