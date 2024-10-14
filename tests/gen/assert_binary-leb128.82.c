
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.82.h"

void test() {
    binaryleb12882Instance instance;
    binaryleb12882Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.82.wasm");
}
