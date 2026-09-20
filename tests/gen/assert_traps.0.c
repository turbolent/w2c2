
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_traps.0.h"

void test() {
    m7_trapsX2E0Instance instance;
    m7_trapsX2E0Instantiate(&instance, resolveTestImports);
    printStart("traps.0.wasm");
}
