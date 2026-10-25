
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.47.h"

void test() {
    m10_exportsX2E47Instance instance;
    m10_exportsX2E47Instantiate(&instance, resolveTestImports);
    printStart("exports.47.wasm");
}
