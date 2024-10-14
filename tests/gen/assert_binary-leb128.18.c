
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.18.h"

void test() {
    binaryleb12818Instance instance;
    binaryleb12818Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.18.wasm");
}
