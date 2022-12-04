
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.55.h"

void test() {
    exports55Instance instance;
    exports55Instantiate(&instance, resolveTestImports);
    printStart("exports.55.wasm");
}
