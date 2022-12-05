
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.24.h"

void test() {
    data24Instance instance;
    data24Instantiate(&instance, resolveTestImports);
    printStart("data.24.wasm");
}
