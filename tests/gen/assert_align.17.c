
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.17.h"

void test() {
    align17Instance instance;
    align17Instantiate(&instance, resolveTestImports);
    printStart("align.17.wasm");
}
