
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.12.h"

void test() {
    binaryleb12812Instance instance;
    binaryleb12812Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.12.wasm");
}
