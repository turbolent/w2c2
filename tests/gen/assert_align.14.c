
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.14.h"

void test() {
    m8_alignX2E14Instance instance;
    m8_alignX2E14Instantiate(&instance, resolveTestImports);
    printStart("align.14.wasm");
}
