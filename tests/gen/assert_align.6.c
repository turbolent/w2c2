
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.6.h"

void test() {
    align6Instance instance;
    align6Instantiate(&instance, resolveTestImports);
    printStart("align.6.wasm");
}
