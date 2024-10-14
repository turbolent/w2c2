
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.0.h"

void test() {
    binary0Instance instance;
    binary0Instantiate(&instance, resolveTestImports);
    printStart("binary.0.wasm");
}
