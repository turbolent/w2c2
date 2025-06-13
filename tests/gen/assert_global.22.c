
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_global.22.h"

void test() {
    global22Instance instance;
    global22Instantiate(&instance, resolveTestImports);
    printStart("global.22.wasm");
}
