
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.15.h"

void test() {
    binaryleb12815Instance instance;
    binaryleb12815Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.15.wasm");
}
