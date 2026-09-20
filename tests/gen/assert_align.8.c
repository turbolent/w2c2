
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.8.h"

void test() {
    m7_alignX2E8Instance instance;
    m7_alignX2E8Instantiate(&instance, resolveTestImports);
    printStart("align.8.wasm");
}
