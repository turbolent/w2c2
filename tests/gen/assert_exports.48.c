
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.48.h"

void test() {
    exports48Instance instance;
    exports48Instantiate(&instance, resolveTestImports);
    printStart("exports.48.wasm");
}
