
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.6.h"

void test() {
    shared6Instance instance;
    shared6Instantiate(&instance, resolveTestImports);
    printStart("shared.6.wasm");
}
