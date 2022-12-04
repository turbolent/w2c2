
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.20.h"

void test() {
    align20Instance instance;
    align20Instantiate(&instance, resolveTestImports);
    printStart("align.20.wasm");
}
