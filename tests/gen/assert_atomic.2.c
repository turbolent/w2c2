
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_atomic.2.h"

void test() {
    m8_atomicX2E2Instance instance;
    m8_atomicX2E2Instantiate(&instance, resolveTestImports);
    printStart("atomic.2.wasm");
}
