
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.45.h"

void test() {
    exports45Instance instance;
    exports45Instantiate(&instance, resolveTestImports);
    printStart("exports.45.wasm");
}
