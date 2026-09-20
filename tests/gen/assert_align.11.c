
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.11.h"

void test() {
    m8_alignX2E11Instance instance;
    m8_alignX2E11Instantiate(&instance, resolveTestImports);
    printStart("align.11.wasm");
}
