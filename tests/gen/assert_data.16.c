
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.16.h"

void test() {
    m7_dataX2E16Instance instance;
    m7_dataX2E16Instantiate(&instance, resolveTestImports);
    printStart("data.16.wasm");
}
