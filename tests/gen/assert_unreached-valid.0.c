
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_unreached-valid.0.h"

void test() {
    m17_unreachedX2DvalidX2E0Instance instance;
    m17_unreachedX2DvalidX2E0Instantiate(&instance, resolveTestImports);
    printStart("unreached-valid.0.wasm");
}
