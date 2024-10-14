
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.80.h"

void test() {
    binaryleb12880Instance instance;
    binaryleb12880Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.80.wasm");
}
