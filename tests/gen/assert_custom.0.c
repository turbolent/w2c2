
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_custom.0.h"

void test() {
    custom0Instance instance;
    custom0Instantiate(&instance, resolveTestImports);
    printStart("custom.0.wasm");
}
