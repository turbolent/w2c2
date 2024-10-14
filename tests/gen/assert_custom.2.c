
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_custom.2.h"

void test() {
    custom2Instance instance;
    custom2Instantiate(&instance, resolveTestImports);
    printStart("custom.2.wasm");
}
