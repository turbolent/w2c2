
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.61.h"

void test() {
    binary61Instance instance;
    binary61Instantiate(&instance, resolveTestImports);
    printStart("binary.61.wasm");
}
