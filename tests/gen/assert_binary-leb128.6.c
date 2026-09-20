
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.6.h"

void test() {
    m15_binaryX2Dleb128X2E6Instance instance;
    m15_binaryX2Dleb128X2E6Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.6.wasm");
}
