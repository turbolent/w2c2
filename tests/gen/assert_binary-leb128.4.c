
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.4.h"

void test() {
    binaryleb1284Instance instance;
    binaryleb1284Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.4.wasm");
}
