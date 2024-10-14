
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_custom.1.h"

void test() {
    custom1Instance instance;
    custom1Instantiate(&instance, resolveTestImports);
    printStart("custom.1.wasm");
}
