
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.92.h"

void test() {
    binary92Instance instance;
    binary92Instantiate(&instance, resolveTestImports);
    printStart("binary.92.wasm");
}
