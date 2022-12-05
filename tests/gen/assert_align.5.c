
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.5.h"

void test() {
    align5Instance instance;
    align5Instantiate(&instance, resolveTestImports);
    printStart("align.5.wasm");
}
