
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.7.h"

void test() {
    m9_exportsX2E7Instance instance;
    m9_exportsX2E7Instantiate(&instance, resolveTestImports);
    printStart("exports.7.wasm");
}
