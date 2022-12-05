
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.32.h"

void test() {
    exports32Instance instance;
    exports32Instantiate(&instance, resolveTestImports);
    printStart("exports.32.wasm");
}
