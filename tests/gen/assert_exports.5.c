
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.5.h"

void test() {
    m9_exportsX2E5Instance instance;
    m9_exportsX2E5Instantiate(&instance, resolveTestImports);
    printStart("exports.5.wasm");
}
