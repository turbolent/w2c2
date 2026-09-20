
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.65.h"

void test() {
    m10_exportsX2E65Instance instance;
    m10_exportsX2E65Instantiate(&instance, resolveTestImports);
    printStart("exports.65.wasm");
}
