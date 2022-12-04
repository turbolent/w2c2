
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.10.h"

void test() {
    data10Instance instance;
    data10Instantiate(&instance, resolveTestImports);
    printStart("data.10.wasm");
}
