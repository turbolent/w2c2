
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.24.h"

void test() {
    m7_dataX2E24Instance instance;
    m7_dataX2E24Instantiate(&instance, resolveTestImports);
    printStart("data.24.wasm");
}
