
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.21.h"

void test() {
    data21Instance instance;
    data21Instantiate(&instance, resolveTestImports);
    printStart("data.21.wasm");
}
