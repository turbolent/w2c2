
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.4.h"

void test() {
    m6_dataX2E4Instance instance;
    m6_dataX2E4Instantiate(&instance, resolveTestImports);
    printStart("data.4.wasm");
}
