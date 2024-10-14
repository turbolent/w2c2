
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.10.h"

void test() {
    binaryleb12810Instance instance;
    binaryleb12810Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.10.wasm");
}
