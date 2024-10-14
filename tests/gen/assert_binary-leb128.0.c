
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.0.h"

void test() {
    binaryleb1280Instance instance;
    binaryleb1280Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.0.wasm");
}
