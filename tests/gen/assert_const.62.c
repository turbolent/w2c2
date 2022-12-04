
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.62.h"

void test() {
    const62Instance instance;
    const62Instantiate(&instance, resolveTestImports);
    printStart("const.62.wasm");
}
