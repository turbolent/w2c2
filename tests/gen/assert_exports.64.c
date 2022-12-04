
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.64.h"

void test() {
    exports64Instance instance;
    exports64Instantiate(&instance, resolveTestImports);
    printStart("exports.64.wasm");
}
