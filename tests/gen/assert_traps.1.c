
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_traps.1.h"

void test() {
    m7_trapsX2E1Instance instance;
    m7_trapsX2E1Instantiate(&instance, resolveTestImports);
    printStart("traps.1.wasm");
}
