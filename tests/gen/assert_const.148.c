
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.148.h"

void test() {
    const148Instance instance;
    const148Instantiate(&instance, resolveTestImports);
    printStart("const.148.wasm");
}
