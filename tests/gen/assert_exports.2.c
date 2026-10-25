
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.2.h"

void test() {
    m9_exportsX2E2Instance instance;
    m9_exportsX2E2Instantiate(&instance, resolveTestImports);
    printStart("exports.2.wasm");
}
