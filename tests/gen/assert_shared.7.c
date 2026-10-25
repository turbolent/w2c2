
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.7.h"

void test() {
    m8_sharedX2E7Instance instance;
    m8_sharedX2E7Instantiate(&instance, resolveTestImports);
    printStart("shared.7.wasm");
}
