
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.25.h"

void test() {
    m7_dataX2E25Instance instance;
    m7_dataX2E25Instantiate(&instance, resolveTestImports);
    printStart("data.25.wasm");
}
