
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.23.h"

void test() {
    binaryleb12823Instance instance;
    binaryleb12823Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.23.wasm");
}
