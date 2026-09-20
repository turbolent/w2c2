
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.58.h"

void test() {
    m10_exportsX2E58Instance instance;
    m10_exportsX2E58Instantiate(&instance, resolveTestImports);
    printStart("exports.58.wasm");
}
