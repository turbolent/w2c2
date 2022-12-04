
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.2.h"

void test() {
    align2Instance instance;
    align2Instantiate(&instance, resolveTestImports);
    printStart("align.2.wasm");
}
