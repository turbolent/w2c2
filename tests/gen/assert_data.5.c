
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.5.h"

void test() {
    data5Instance instance;
    data5Instantiate(&instance, resolveTestImports);
    printStart("data.5.wasm");
}
