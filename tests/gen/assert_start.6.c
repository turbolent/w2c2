
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_start.6.h"

void test() {
    start6Instance instance;
    start6Instantiate(&instance, resolveTestImports);
    printStart("start.6.wasm");
}
