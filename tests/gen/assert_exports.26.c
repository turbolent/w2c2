
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.26.h"

void test() {
    m10_exportsX2E26Instance instance;
    m10_exportsX2E26Instantiate(&instance, resolveTestImports);
    printStart("exports.26.wasm");
}
