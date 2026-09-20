
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.24.h"

void test() {
    m10_exportsX2E24Instance instance;
    m10_exportsX2E24Instantiate(&instance, resolveTestImports);
    printStart("exports.24.wasm");
}
