
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_traps.2.h"

void test() {
    traps2Instance instance;
    traps2Instantiate(&instance, resolveTestImports);
    printStart("traps.2.wasm");
}
