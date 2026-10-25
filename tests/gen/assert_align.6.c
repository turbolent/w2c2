
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.6.h"

void test() {
    m7_alignX2E6Instance instance;
    m7_alignX2E6Instantiate(&instance, resolveTestImports);
    printStart("align.6.wasm");
}
