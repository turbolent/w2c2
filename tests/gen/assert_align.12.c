
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.12.h"

void test() {
    align12Instance instance;
    align12Instantiate(&instance, resolveTestImports);
    printStart("align.12.wasm");
}
