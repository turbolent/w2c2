
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.3.h"

void test() {
    shared3Instance instance;
    shared3Instantiate(&instance, resolveTestImports);
    printStart("shared.3.wasm");
}
