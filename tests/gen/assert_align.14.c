
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.14.h"

void test() {
    align14Instance instance;
    align14Instantiate(&instance, resolveTestImports);
    printStart("align.14.wasm");
}
