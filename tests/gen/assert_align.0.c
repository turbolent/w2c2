
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.0.h"

void test() {
    m7_alignX2E0Instance instance;
    m7_alignX2E0Instantiate(&instance, resolveTestImports);
    printStart("align.0.wasm");
}
