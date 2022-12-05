
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.13.h"

void test() {
    align13Instance instance;
    align13Instantiate(&instance, resolveTestImports);
    printStart("align.13.wasm");
}
