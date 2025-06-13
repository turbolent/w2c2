
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_shared.7.h"

void test() {
    shared7Instance instance;
    shared7Instantiate(&instance, resolveTestImports);
    printStart("shared.7.wasm");
}
