
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.27.h"

void test() {
    m10_exportsX2E27Instance instance;
    m10_exportsX2E27Instantiate(&instance, resolveTestImports);
    printStart("exports.27.wasm");
}
