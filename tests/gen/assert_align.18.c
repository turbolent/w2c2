
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.18.h"

void test() {
    align18Instance instance;
    align18Instantiate(&instance, resolveTestImports);
    printStart("align.18.wasm");
}
