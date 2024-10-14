
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.98.h"

void test() {
    binary98Instance instance;
    binary98Instantiate(&instance, resolveTestImports);
    printStart("binary.98.wasm");
}
