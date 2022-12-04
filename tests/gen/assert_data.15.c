
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.15.h"

void test() {
    data15Instance instance;
    data15Instantiate(&instance, resolveTestImports);
    printStart("data.15.wasm");
}
