
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.27.h"

void test() {
    exports27Instance instance;
    exports27Instantiate(&instance, resolveTestImports);
    printStart("exports.27.wasm");
}
