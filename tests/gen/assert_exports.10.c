
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.10.h"

void test() {
    m10_exportsX2E10Instance instance;
    m10_exportsX2E10Instantiate(&instance, resolveTestImports);
    printStart("exports.10.wasm");
}
