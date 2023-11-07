
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.5.h"

void test() {
    shared5Instance instance;
    shared5Instantiate(&instance, resolveTestImports);
    printStart("shared.5.wasm");
}
