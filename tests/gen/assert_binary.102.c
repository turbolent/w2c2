
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.102.h"

void test() {
    binary102Instance instance;
    binary102Instantiate(&instance, resolveTestImports);
    printStart("binary.102.wasm");
}
