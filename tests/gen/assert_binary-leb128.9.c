
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.9.h"

void test() {
    binaryleb1289Instance instance;
    binaryleb1289Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.9.wasm");
}
