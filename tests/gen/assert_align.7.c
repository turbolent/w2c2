
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.7.h"

void test() {
    m7_alignX2E7Instance instance;
    m7_alignX2E7Instantiate(&instance, resolveTestImports);
    printStart("align.7.wasm");
}
