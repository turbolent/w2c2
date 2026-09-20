
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_runtime_lifecycle.2.h"

void test() {
    m19_runtimeX5FlifecycleX2E2Instance instance;
    m19_runtimeX5FlifecycleX2E2Instantiate(&instance, resolveTestImports);
    printStart("runtime_lifecycle.2.wasm");
}
