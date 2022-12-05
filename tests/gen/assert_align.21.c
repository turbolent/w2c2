
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.21.h"

void test() {
    align21Instance instance;
    align21Instantiate(&instance, resolveTestImports);
    printStart("align.21.wasm");
}
