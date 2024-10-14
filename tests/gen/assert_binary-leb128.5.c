
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.5.h"

void test() {
    binaryleb1285Instance instance;
    binaryleb1285Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.5.wasm");
}
