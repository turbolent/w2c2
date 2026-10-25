
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.8.h"

void test() {
    m15_binaryX2Dleb128X2E8Instance instance;
    m15_binaryX2Dleb128X2E8Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.8.wasm");
}
