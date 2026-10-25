
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.13.h"

void test() {
    m16_binaryX2Dleb128X2E13Instance instance;
    m16_binaryX2Dleb128X2E13Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.13.wasm");
}
