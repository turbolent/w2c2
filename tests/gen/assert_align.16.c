
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.16.h"

void test() {
    align16Instance instance;
    align16Instantiate(&instance, resolveTestImports);
    printStart("align.16.wasm");
}
