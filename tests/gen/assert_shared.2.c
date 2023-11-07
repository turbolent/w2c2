
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.2.h"

void test() {
    shared2Instance instance;
    shared2Instantiate(&instance, resolveTestImports);
    printStart("shared.2.wasm");
}
