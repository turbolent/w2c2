
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_exports.44.h"

void test() {
    m10_exportsX2E44Instance instance;
    m10_exportsX2E44Instantiate(&instance, resolveTestImports);
    printStart("exports.44.wasm");
}
