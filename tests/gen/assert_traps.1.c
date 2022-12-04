
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_traps.1.h"

void test() {
    traps1Instance instance;
    traps1Instantiate(&instance, resolveTestImports);
    printStart("traps.1.wasm");
}
