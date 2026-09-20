
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.22.h"

void test() {
    m16_binaryX2Dleb128X2E22Instance instance;
    m16_binaryX2Dleb128X2E22Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.22.wasm");
}
