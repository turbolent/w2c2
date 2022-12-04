
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.18.h"

void test() {
    exports18Instance instance;
    exports18Instantiate(&instance, resolveTestImports);
    printStart("exports.18.wasm");
}
