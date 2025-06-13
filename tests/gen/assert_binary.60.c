
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.60.h"

void test() {
    binary60Instance instance;
    binary60Instantiate(&instance, resolveTestImports);
    printStart("binary.60.wasm");
}
