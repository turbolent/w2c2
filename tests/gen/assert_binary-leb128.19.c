
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.19.h"

void test() {
    binaryleb12819Instance instance;
    binaryleb12819Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.19.wasm");
}
