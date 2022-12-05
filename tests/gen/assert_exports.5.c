
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.5.h"

void test() {
    exports5Instance instance;
    exports5Instantiate(&instance, resolveTestImports);
    printStart("exports.5.wasm");
}
