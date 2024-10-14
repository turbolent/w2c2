
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.69.h"

void test() {
    exports69Instance instance;
    exports69Instantiate(&instance, resolveTestImports);
    printStart("exports.69.wasm");
}
