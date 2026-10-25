
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.9.h"

void test() {
    m9_exportsX2E9Instance instance;
    m9_exportsX2E9Instantiate(&instance, resolveTestImports);
    printStart("exports.9.wasm");
}
