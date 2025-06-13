
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_global.25.h"

void test() {
    global25Instance instance;
    global25Instantiate(&instance, resolveTestImports);
    printStart("global.25.wasm");
}
