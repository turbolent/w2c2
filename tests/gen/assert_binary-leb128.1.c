
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.1.h"

void test() {
    m15_binaryX2Dleb128X2E1Instance instance;
    m15_binaryX2Dleb128X2E1Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.1.wasm");
}
