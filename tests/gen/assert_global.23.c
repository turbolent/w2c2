
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_global.23.h"

void test() {
    global23Instance instance;
    global23Instantiate(&instance, resolveTestImports);
    printStart("global.23.wasm");
}
