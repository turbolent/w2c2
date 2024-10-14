
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.49.h"

void test() {
    exports49Instance instance;
    exports49Instantiate(&instance, resolveTestImports);
    printStart("exports.49.wasm");
}
