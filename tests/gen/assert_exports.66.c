
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.66.h"

void test() {
    m10_exportsX2E66Instance instance;
    m10_exportsX2E66Instantiate(&instance, resolveTestImports);
    printStart("exports.66.wasm");
}
