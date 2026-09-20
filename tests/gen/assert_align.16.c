
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.16.h"

void test() {
    m8_alignX2E16Instance instance;
    m8_alignX2E16Instantiate(&instance, resolveTestImports);
    printStart("align.16.wasm");
}
