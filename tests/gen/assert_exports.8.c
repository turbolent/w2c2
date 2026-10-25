
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.8.h"

void test() {
    m9_exportsX2E8Instance instance;
    m9_exportsX2E8Instantiate(&instance, resolveTestImports);
    printStart("exports.8.wasm");
}
