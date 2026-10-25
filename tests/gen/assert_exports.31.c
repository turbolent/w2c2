
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.31.h"

void test() {
    m10_exportsX2E31Instance instance;
    m10_exportsX2E31Instantiate(&instance, resolveTestImports);
    printStart("exports.31.wasm");
}
