
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_custom.1.h"

void test() {
    m8_customX2E1Instance instance;
    m8_customX2E1Instantiate(&instance, resolveTestImports);
    printStart("custom.1.wasm");
}
