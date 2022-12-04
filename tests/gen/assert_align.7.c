
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.7.h"

void test() {
    align7Instance instance;
    align7Instantiate(&instance, resolveTestImports);
    printStart("align.7.wasm");
}
