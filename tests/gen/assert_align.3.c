
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.3.h"

void test() {
    align3Instance instance;
    align3Instantiate(&instance, resolveTestImports);
    printStart("align.3.wasm");
}
