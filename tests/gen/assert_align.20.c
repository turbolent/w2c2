
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.20.h"

void test() {
    m8_alignX2E20Instance instance;
    m8_alignX2E20Instantiate(&instance, resolveTestImports);
    printStart("align.20.wasm");
}
