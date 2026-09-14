
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_runtime_lifecycle.0.h"

void test() {
    runtimelifecycle0Instance instance;
    runtimelifecycle0Instantiate(&instance, resolveTestImports);
    printStart("runtime_lifecycle.0.wasm");
}
