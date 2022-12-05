
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.4.h"

void test() {
    data4Instance instance;
    data4Instantiate(&instance, resolveTestImports);
    printStart("data.4.wasm");
}
