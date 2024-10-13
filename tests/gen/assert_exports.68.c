
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.68.h"

void test() {
    exports68Instance instance;
    exports68Instantiate(&instance, resolveTestImports);
    printStart("exports.68.wasm");
}
