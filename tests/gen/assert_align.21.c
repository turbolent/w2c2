
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.21.h"

void test() {
    m8_alignX2E21Instance instance;
    m8_alignX2E21Instantiate(&instance, resolveTestImports);
    printStart("align.21.wasm");
}
