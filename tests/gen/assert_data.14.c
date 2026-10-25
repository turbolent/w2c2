
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.14.h"

void test() {
    m7_dataX2E14Instance instance;
    m7_dataX2E14Instantiate(&instance, resolveTestImports);
    printStart("data.14.wasm");
}
