
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.8.h"

void test() {
    align8Instance instance;
    align8Instantiate(&instance, resolveTestImports);
    printStart("align.8.wasm");
}
