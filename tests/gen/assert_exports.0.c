
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.0.h"

void test() {
    m9_exportsX2E0Instance instance;
    m9_exportsX2E0Instantiate(&instance, resolveTestImports);
    printStart("exports.0.wasm");
}
