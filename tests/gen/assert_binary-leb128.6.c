
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.6.h"

void test() {
    binaryleb1286Instance instance;
    binaryleb1286Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.6.wasm");
}
