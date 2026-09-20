
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.12.h"

void test() {
    m8_alignX2E12Instance instance;
    m8_alignX2E12Instantiate(&instance, resolveTestImports);
    printStart("align.12.wasm");
}
