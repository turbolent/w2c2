
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.4.h"

void test() {
    align4Instance instance;
    align4Instantiate(&instance, resolveTestImports);
    printStart("align.4.wasm");
}
