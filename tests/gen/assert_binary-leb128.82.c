
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.82.h"

void test() {
    m16_binaryX2Dleb128X2E82Instance instance;
    m16_binaryX2Dleb128X2E82Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.82.wasm");
}
