
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.69.h"

void test() {
    binary69Instance instance;
    binary69Instantiate(&instance, resolveTestImports);
    printStart("binary.69.wasm");
}
