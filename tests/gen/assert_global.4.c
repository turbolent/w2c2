
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_global.4.h"

void test() {
    global4Instance instance;
    global4Instantiate(&instance, resolveTestImports);
    printStart("global.4.wasm");
}
