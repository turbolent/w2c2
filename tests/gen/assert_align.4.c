
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.4.h"

void test() {
    m7_alignX2E4Instance instance;
    m7_alignX2E4Instantiate(&instance, resolveTestImports);
    printStart("align.4.wasm");
}
