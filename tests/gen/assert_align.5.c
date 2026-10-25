
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.5.h"

void test() {
    m7_alignX2E5Instance instance;
    m7_alignX2E5Instantiate(&instance, resolveTestImports);
    printStart("align.5.wasm");
}
