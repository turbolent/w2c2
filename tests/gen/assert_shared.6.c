
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.6.h"

void test() {
    m8_sharedX2E6Instance instance;
    m8_sharedX2E6Instantiate(&instance, resolveTestImports);
    printStart("shared.6.wasm");
}
