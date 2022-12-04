
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.16.h"

void test() {
    data16Instance instance;
    data16Instantiate(&instance, resolveTestImports);
    printStart("data.16.wasm");
}
