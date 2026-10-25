
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_traps.2.h"

void test() {
    m7_trapsX2E2Instance instance;
    m7_trapsX2E2Instantiate(&instance, resolveTestImports);
    printStart("traps.2.wasm");
}
