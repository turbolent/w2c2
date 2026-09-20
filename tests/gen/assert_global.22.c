
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_global.22.h"

void test() {
    m9_globalX2E22Instance instance;
    m9_globalX2E22Instantiate(&instance, resolveTestImports);
    printStart("global.22.wasm");
}
