
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.8.h"

void test() {
    binaryleb1288Instance instance;
    binaryleb1288Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.8.wasm");
}
