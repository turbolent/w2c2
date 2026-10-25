
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.5.h"

void test() {
    m8_sharedX2E5Instance instance;
    m8_sharedX2E5Instantiate(&instance, resolveTestImports);
    printStart("shared.5.wasm");
}
