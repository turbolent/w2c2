
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.12.h"

void test() {
    data12Instance instance;
    data12Instantiate(&instance, resolveTestImports);
    printStart("data.12.wasm");
}
