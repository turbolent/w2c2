
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.18.h"

void test() {
    m8_alignX2E18Instance instance;
    m8_alignX2E18Instantiate(&instance, resolveTestImports);
    printStart("align.18.wasm");
}
