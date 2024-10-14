
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.21.h"

void test() {
    binaryleb12821Instance instance;
    binaryleb12821Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.21.wasm");
}
