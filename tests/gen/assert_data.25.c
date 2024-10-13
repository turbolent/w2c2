
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.25.h"

void test() {
    data25Instance instance;
    data25Instantiate(&instance, resolveTestImports);
    printStart("data.25.wasm");
}
