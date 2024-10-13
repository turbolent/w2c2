
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.26.h"

void test() {
    exports26Instance instance;
    exports26Instantiate(&instance, resolveTestImports);
    printStart("exports.26.wasm");
}
