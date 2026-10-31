#include "test.h"
#include "test_runtime_lifecycle.0.h"

void test(void) {
    static m19_runtimeX5FlifecycleX2E0Instance instance;
    m19_runtimeX5FlifecycleX2E0Instantiate(&instance, resolveTestImports);
    printStart("runtime_lifecycle.0.wasm");
    m19_runtimeX5FlifecycleX2E0FreeInstance(&instance);
}
