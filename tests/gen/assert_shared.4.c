
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.4.h"

void test() {
    shared4Instance instance;
    shared4Instantiate(&instance, resolveTestImports);
    printStart("shared.4.wasm");
}
