
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.19.h"

void test() {
    m7_dataX2E19Instance instance;
    m7_dataX2E19Instantiate(&instance, resolveTestImports);
    printStart("data.19.wasm");
}
