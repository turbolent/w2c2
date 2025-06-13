
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.11.h"

void test() {
    binaryleb12811Instance instance;
    binaryleb12811Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.11.wasm");
}
