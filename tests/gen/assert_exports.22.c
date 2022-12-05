
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.22.h"

void test() {
    exports22Instance instance;
    exports22Instantiate(&instance, resolveTestImports);
    printStart("exports.22.wasm");
}
