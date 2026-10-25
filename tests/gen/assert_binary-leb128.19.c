
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary-leb128.19.h"

void test() {
    m16_binaryX2Dleb128X2E19Instance instance;
    m16_binaryX2Dleb128X2E19Instantiate(&instance, resolveTestImports);
    printStart("binary-leb128.19.wasm");
}
