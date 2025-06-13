
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.84.h"

void test() {
    binaryleb12884Instance instance;
    binaryleb12884Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.84.wasm");
}
