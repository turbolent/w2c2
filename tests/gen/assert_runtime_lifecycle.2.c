#include "test.h"
#include "test_runtime_lifecycle.2.h"

void test(void) {
    static m19_runtimeX5FlifecycleX2E2Instance instance;
    m19_runtimeX5FlifecycleX2E2Instantiate(&instance, resolveTestImports);
    printStart("runtime_lifecycle.2.wasm");
    m19_runtimeX5FlifecycleX2E2FreeInstance(&instance);
}
