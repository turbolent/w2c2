
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.1.h"

void test() {
    shared1Instance instance;
    shared1Instantiate(&instance, resolveTestImports);
    printStart("shared.1.wasm");
}
