
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.3.h"

void test() {
    m8_sharedX2E3Instance instance;
    m8_sharedX2E3Instantiate(&instance, resolveTestImports);
    printStart("shared.3.wasm");
}
