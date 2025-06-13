
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.109.h"

void test() {
    binary109Instance instance;
    binary109Instantiate(&instance, resolveTestImports);
    printStart("binary.109.wasm");
}
