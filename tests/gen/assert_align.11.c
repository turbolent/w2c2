
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.11.h"

void test() {
    align11Instance instance;
    align11Instantiate(&instance, resolveTestImports);
    printStart("align.11.wasm");
}
