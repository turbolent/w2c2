
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_global.3.h"

void test() {
    global3Instance instance;
    global3Instantiate(&instance, resolveTestImports);
    printStart("global.3.wasm");
}
