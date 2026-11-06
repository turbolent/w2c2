#include "test.h"
#include "test_memory_init.95.h"

void test(void) {
    static m14_memoryX5FinitX2E95Instance instance;
    m14_memoryX5FinitX2E95Instantiate(&instance, resolveTestImports);
    printStart("memory_init.95.wasm");
    (void)(m14_memoryX5FinitX2E95Export4_test(&instance));
    printOK("test()");
    m14_memoryX5FinitX2E95FreeInstance(&instance);
}
