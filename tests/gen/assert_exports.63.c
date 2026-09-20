
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.63.h"

void test() {
    m10_exportsX2E63Instance instance;
    m10_exportsX2E63Instantiate(&instance, resolveTestImports);
    printStart("exports.63.wasm");
}
