
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.2.h"

void test() {
    binaryleb1282Instance instance;
    binaryleb1282Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.2.wasm");
}
