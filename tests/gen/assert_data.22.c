
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.22.h"

void test() {
    data22Instance instance;
    data22Instantiate(&instance, resolveTestImports);
    printStart("data.22.wasm");
}
