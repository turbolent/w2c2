
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.40.h"

void test() {
    m10_exportsX2E40Instance instance;
    m10_exportsX2E40Instantiate(&instance, resolveTestImports);
    printStart("exports.40.wasm");
}
