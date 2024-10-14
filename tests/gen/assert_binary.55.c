
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.55.h"

void test() {
    binary55Instance instance;
    binary55Instantiate(&instance, resolveTestImports);
    printStart("binary.55.wasm");
}
