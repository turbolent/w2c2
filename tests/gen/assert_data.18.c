
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.18.h"

void test() {
    m7_dataX2E18Instance instance;
    m7_dataX2E18Instantiate(&instance, resolveTestImports);
    printStart("data.18.wasm");
}
