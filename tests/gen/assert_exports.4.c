
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.4.h"

void test() {
    m9_exportsX2E4Instance instance;
    m9_exportsX2E4Instantiate(&instance, resolveTestImports);
    printStart("exports.4.wasm");
}
