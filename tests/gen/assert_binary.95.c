
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_binary.95.h"

void test() {
    binary95Instance instance;
    binary95Instantiate(&instance, resolveTestImports);
    printStart("binary.95.wasm");
}
