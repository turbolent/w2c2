
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.52.h"

void test() {
    exports52Instance instance;
    exports52Instantiate(&instance, resolveTestImports);
    printStart("exports.52.wasm");
}
