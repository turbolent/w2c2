
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.0.h"

void test() {
    shared0Instance instance;
    shared0Instantiate(&instance, resolveTestImports);
    printStart("shared.0.wasm");
}
