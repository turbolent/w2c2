
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.11.h"

void test() {
    data11Instance instance;
    data11Instantiate(&instance, resolveTestImports);
    printStart("data.11.wasm");
}
