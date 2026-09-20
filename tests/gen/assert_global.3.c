
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_global.3.h"

void test() {
    m8_globalX2E3Instance instance;
    m8_globalX2E3Instantiate(&instance, resolveTestImports);
    printStart("global.3.wasm");
}
