
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.26.h"

void test() {
    data26Instance instance;
    data26Instantiate(&instance, resolveTestImports);
    printStart("data.26.wasm");
}
