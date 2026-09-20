
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.8.h"

void test() {
    m8_sharedX2E8Instance instance;
    m8_sharedX2E8Instantiate(&instance, resolveTestImports);
    printStart("shared.8.wasm");
}
