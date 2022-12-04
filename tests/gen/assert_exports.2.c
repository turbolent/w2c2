
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.2.h"

void test() {
    exports2Instance instance;
    exports2Instantiate(&instance, resolveTestImports);
    printStart("exports.2.wasm");
}
