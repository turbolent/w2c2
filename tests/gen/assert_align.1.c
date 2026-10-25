
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.1.h"

void test() {
    m7_alignX2E1Instance instance;
    m7_alignX2E1Instantiate(&instance, resolveTestImports);
    printStart("align.1.wasm");
}
