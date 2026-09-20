
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.22.h"

void test() {
    m7_dataX2E22Instance instance;
    m7_dataX2E22Instantiate(&instance, resolveTestImports);
    printStart("data.22.wasm");
}
