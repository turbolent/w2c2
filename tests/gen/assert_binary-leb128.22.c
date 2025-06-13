
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.22.h"

void test() {
    binaryleb12822Instance instance;
    binaryleb12822Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.22.wasm");
}
