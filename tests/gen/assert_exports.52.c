
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.52.h"

void test() {
    m10_exportsX2E52Instance instance;
    m10_exportsX2E52Instantiate(&instance, resolveTestImports);
    printStart("exports.52.wasm");
}
