
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_global.4.h"

void test() {
    m8_globalX2E4Instance instance;
    m8_globalX2E4Instantiate(&instance, resolveTestImports);
    printStart("global.4.wasm");
}
