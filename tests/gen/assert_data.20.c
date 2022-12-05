
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.20.h"

void test() {
    data20Instance instance;
    data20Instantiate(&instance, resolveTestImports);
    printStart("data.20.wasm");
}
