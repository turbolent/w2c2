
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_runtime_lifecycle.1.h"

void test() {
    runtimelifecycle1Instance instance;
    runtimelifecycle1Instantiate(&instance, resolveTestImports);
    printStart("runtime_lifecycle.1.wasm");
}
