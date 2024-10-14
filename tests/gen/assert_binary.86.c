
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.86.h"

void test() {
    binary86Instance instance;
    binary86Instantiate(&instance, resolveTestImports);
    printStart("binary.86.wasm");
}
