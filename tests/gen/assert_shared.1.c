
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.1.h"

void test() {
    m8_sharedX2E1Instance instance;
    m8_sharedX2E1Instantiate(&instance, resolveTestImports);
    printStart("shared.1.wasm");
}
