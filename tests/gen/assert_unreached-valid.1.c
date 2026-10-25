
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_unreached-valid.1.h"

void test() {
    m17_unreachedX2DvalidX2E1Instance instance;
    m17_unreachedX2DvalidX2E1Instantiate(&instance, resolveTestImports);
    printStart("unreached-valid.1.wasm");
}
