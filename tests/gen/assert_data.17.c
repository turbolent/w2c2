
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.17.h"

void test() {
    data17Instance instance;
    data17Instantiate(&instance, resolveTestImports);
    printStart("data.17.wasm");
}
