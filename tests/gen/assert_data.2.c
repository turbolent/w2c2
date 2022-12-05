
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.2.h"

void test() {
    data2Instance instance;
    data2Instantiate(&instance, resolveTestImports);
    printStart("data.2.wasm");
}
