
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_runtime_lifecycle.2.h"

void test() {
    runtimelifecycle2Instance instance;
    runtimelifecycle2Instantiate(&instance, resolveTestImports);
    printStart("runtime_lifecycle.2.wasm");
}
