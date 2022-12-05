
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_global.20.h"

void test() {
    global20Instance instance;
    global20Instantiate(&instance, resolveTestImports);
    printStart("global.20.wasm");
}
