
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_custom.0.h"

void test() {
    m8_customX2E0Instance instance;
    m8_customX2E0Instantiate(&instance, resolveTestImports);
    printStart("custom.0.wasm");
}
