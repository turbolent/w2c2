
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.14.h"

void test() {
    binaryleb12814Instance instance;
    binaryleb12814Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.14.wasm");
}
