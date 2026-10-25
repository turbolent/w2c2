
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.13.h"

void test() {
    m8_alignX2E13Instance instance;
    m8_alignX2E13Instantiate(&instance, resolveTestImports);
    printStart("align.13.wasm");
}
