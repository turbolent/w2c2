
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.58.h"

void test() {
    exports58Instance instance;
    exports58Instantiate(&instance, resolveTestImports);
    printStart("exports.58.wasm");
}
