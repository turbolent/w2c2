
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.23.h"

void test() {
    m7_dataX2E23Instance instance;
    m7_dataX2E23Instantiate(&instance, resolveTestImports);
    printStart("data.23.wasm");
}
