
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_start.5.h"

void test() {
    start5Instance instance;
    start5Instantiate(&instance, resolveTestImports);
    printStart("start.5.wasm");
}
