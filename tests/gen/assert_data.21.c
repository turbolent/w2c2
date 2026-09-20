
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.21.h"

void test() {
    m7_dataX2E21Instance instance;
    m7_dataX2E21Instantiate(&instance, resolveTestImports);
    printStart("data.21.wasm");
}
