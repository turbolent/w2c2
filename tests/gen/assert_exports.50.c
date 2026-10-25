
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.50.h"

void test() {
    m10_exportsX2E50Instance instance;
    m10_exportsX2E50Instantiate(&instance, resolveTestImports);
    printStart("exports.50.wasm");
}
