
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.15.h"

void test() {
    m8_alignX2E15Instance instance;
    m8_alignX2E15Instantiate(&instance, resolveTestImports);
    printStart("align.15.wasm");
}
