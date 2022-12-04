
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.23.h"

void test() {
    data23Instance instance;
    data23Instantiate(&instance, resolveTestImports);
    printStart("data.23.wasm");
}
