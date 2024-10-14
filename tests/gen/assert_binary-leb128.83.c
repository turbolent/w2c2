
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.83.h"

void test() {
    binaryleb12883Instance instance;
    binaryleb12883Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.83.wasm");
}
