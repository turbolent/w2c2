
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.72.h"

void test() {
    binary72Instance instance;
    binary72Instantiate(&instance, resolveTestImports);
    printStart("binary.72.wasm");
}
