
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.20.h"

void test() {
    m7_dataX2E20Instance instance;
    m7_dataX2E20Instantiate(&instance, resolveTestImports);
    printStart("data.20.wasm");
}
