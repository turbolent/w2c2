
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.16.h"

void test() {
    m16_binaryX2Dleb128X2E16Instance instance;
    m16_binaryX2Dleb128X2E16Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.16.wasm");
}
