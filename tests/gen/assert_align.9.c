
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.9.h"

void test() {
    align9Instance instance;
    align9Instantiate(&instance, resolveTestImports);
    printStart("align.9.wasm");
}
