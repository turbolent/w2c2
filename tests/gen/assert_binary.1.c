
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.1.h"

void test() {
    binary1Instance instance;
    binary1Instantiate(&instance, resolveTestImports);
    printStart("binary.1.wasm");
}
