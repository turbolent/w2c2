
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_traps.0.h"

void test() {
    traps0Instance instance;
    traps0Instantiate(&instance, resolveTestImports);
    printStart("traps.0.wasm");
}
