
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.9.h"

void test() {
    m7_alignX2E9Instance instance;
    m7_alignX2E9Instantiate(&instance, resolveTestImports);
    printStart("align.9.wasm");
}
