
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.18.h"

void test() {
    data18Instance instance;
    data18Instantiate(&instance, resolveTestImports);
    printStart("data.18.wasm");
}
