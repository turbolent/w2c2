
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.39.h"

void test() {
    m10_exportsX2E39Instance instance;
    m10_exportsX2E39Instantiate(&instance, resolveTestImports);
    printStart("exports.39.wasm");
}
