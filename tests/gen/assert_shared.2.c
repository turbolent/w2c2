
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.2.h"

void test() {
    m8_sharedX2E2Instance instance;
    m8_sharedX2E2Instantiate(&instance, resolveTestImports);
    printStart("shared.2.wasm");
}
