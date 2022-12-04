
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_traps.3.h"

void test() {
    traps3Instance instance;
    traps3Instantiate(&instance, resolveTestImports);
    printStart("traps.3.wasm");
}
