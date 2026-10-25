
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.26.h"

void test() {
    m7_dataX2E26Instance instance;
    m7_dataX2E26Instantiate(&instance, resolveTestImports);
    printStart("data.26.wasm");
}
