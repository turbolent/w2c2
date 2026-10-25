
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.6.h"

void test() {
    m9_exportsX2E6Instance instance;
    m9_exportsX2E6Instantiate(&instance, resolveTestImports);
    printStart("exports.6.wasm");
}
