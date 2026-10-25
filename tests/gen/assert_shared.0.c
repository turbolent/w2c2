
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.0.h"

void test() {
    m8_sharedX2E0Instance instance;
    m8_sharedX2E0Instantiate(&instance, resolveTestImports);
    printStart("shared.0.wasm");
}
