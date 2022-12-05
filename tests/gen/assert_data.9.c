
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.9.h"

void test() {
    data9Instance instance;
    data9Instantiate(&instance, resolveTestImports);
    printStart("data.9.wasm");
}
