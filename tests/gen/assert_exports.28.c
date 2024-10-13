
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.28.h"

void test() {
    exports28Instance instance;
    exports28Instantiate(&instance, resolveTestImports);
    printStart("exports.28.wasm");
}
