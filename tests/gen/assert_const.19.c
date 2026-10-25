
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.19.h"

void test() {
    m8_constX2E19Instance instance;
    m8_constX2E19Instantiate(&instance, resolveTestImports);
    printStart("const.19.wasm");
}
