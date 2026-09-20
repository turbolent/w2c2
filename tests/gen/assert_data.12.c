
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.12.h"

void test() {
    m7_dataX2E12Instance instance;
    m7_dataX2E12Instantiate(&instance, resolveTestImports);
    printStart("data.12.wasm");
}
