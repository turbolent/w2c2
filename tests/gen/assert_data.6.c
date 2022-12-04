
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.6.h"

void test() {
    data6Instance instance;
    data6Instantiate(&instance, resolveTestImports);
    printStart("data.6.wasm");
}
