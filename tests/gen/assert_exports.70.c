
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.70.h"

void test() {
    m10_exportsX2E70Instance instance;
    m10_exportsX2E70Instantiate(&instance, resolveTestImports);
    printStart("exports.70.wasm");
}
