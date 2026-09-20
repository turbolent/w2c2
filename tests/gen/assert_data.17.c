
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.17.h"

void test() {
    m7_dataX2E17Instance instance;
    m7_dataX2E17Instantiate(&instance, resolveTestImports);
    printStart("data.17.wasm");
}
