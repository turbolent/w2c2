
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.22.h"

void test() {
    m8_alignX2E22Instance instance;
    m8_alignX2E22Instantiate(&instance, resolveTestImports);
    printStart("align.22.wasm");
}
