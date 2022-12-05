
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.3.h"

void test() {
    data3Instance instance;
    data3Instantiate(&instance, resolveTestImports);
    printStart("data.3.wasm");
}
