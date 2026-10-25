
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.74.h"

void test() {
    m10_exportsX2E74Instance instance;
    m10_exportsX2E74Instantiate(&instance, resolveTestImports);
    printStart("exports.74.wasm");
}
