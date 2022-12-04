
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.13.h"

void test() {
    data13Instance instance;
    data13Instantiate(&instance, resolveTestImports);
    printStart("data.13.wasm");
}
