
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.11.h"

void test() {
    m7_dataX2E11Instance instance;
    m7_dataX2E11Instantiate(&instance, resolveTestImports);
    printStart("data.11.wasm");
}
