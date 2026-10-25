
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.10.h"

void test() {
    m8_alignX2E10Instance instance;
    m8_alignX2E10Instantiate(&instance, resolveTestImports);
    printStart("align.10.wasm");
}
