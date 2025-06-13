
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.1.h"

void test() {
    binaryleb1281Instance instance;
    binaryleb1281Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.1.wasm");
}
