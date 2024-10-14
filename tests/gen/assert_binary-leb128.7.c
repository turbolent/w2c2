
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.7.h"

void test() {
    binaryleb1287Instance instance;
    binaryleb1287Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.7.wasm");
}
