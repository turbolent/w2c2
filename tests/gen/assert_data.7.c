
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.7.h"

void test() {
    data7Instance instance;
    data7Instantiate(&instance, resolveTestImports);
    printStart("data.7.wasm");
}
