
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.16.h"

void test() {
    binaryleb12816Instance instance;
    binaryleb12816Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.16.wasm");
}
