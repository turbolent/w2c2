
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.13.h"

void test() {
    binaryleb12813Instance instance;
    binaryleb12813Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.13.wasm");
}
