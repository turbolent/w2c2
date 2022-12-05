
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.62.h"

void test() {
    exports62Instance instance;
    exports62Instantiate(&instance, resolveTestImports);
    printStart("exports.62.wasm");
}
