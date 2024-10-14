
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.20.h"

void test() {
    binaryleb12820Instance instance;
    binaryleb12820Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.20.wasm");
}
