
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.4.h"

void test() {
    m8_sharedX2E4Instance instance;
    m8_sharedX2E4Instantiate(&instance, resolveTestImports);
    printStart("shared.4.wasm");
}
