
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.17.h"

void test() {
    binaryleb12817Instance instance;
    binaryleb12817Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.17.wasm");
}
