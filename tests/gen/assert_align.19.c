
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.19.h"

void test() {
    m8_alignX2E19Instance instance;
    m8_alignX2E19Instantiate(&instance, resolveTestImports);
    printStart("align.19.wasm");
}
