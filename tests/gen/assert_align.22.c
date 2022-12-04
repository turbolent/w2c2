
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.22.h"

void test() {
    align22Instance instance;
    align22Instantiate(&instance, resolveTestImports);
    printStart("align.22.wasm");
}
