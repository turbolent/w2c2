
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.17.h"

void test() {
    exports17Instance instance;
    exports17Instantiate(&instance, resolveTestImports);
    printStart("exports.17.wasm");
}
