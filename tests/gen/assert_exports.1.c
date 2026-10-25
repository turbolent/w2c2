
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.1.h"

void test() {
    m9_exportsX2E1Instance instance;
    m9_exportsX2E1Instantiate(&instance, resolveTestImports);
    printStart("exports.1.wasm");
}
