
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_global.25.h"

void test() {
    m9_globalX2E25Instance instance;
    m9_globalX2E25Instantiate(&instance, resolveTestImports);
    printStart("global.25.wasm");
}
