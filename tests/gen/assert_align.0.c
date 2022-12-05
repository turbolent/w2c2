
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.0.h"

void test() {
    align0Instance instance;
    align0Instantiate(&instance, resolveTestImports);
    printStart("align.0.wasm");
}
