
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_start.7.h"

void test() {
    start7Instance instance;
    start7Instantiate(&instance, resolveTestImports);
    printStart("start.7.wasm");
}
