
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.3.h"

void test() {
    binaryleb1283Instance instance;
    binaryleb1283Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.3.wasm");
}
