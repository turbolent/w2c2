
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.2.h"

void test() {
    m7_alignX2E2Instance instance;
    m7_alignX2E2Instantiate(&instance, resolveTestImports);
    printStart("align.2.wasm");
}
