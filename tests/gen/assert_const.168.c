
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.168.h"

void test() {
    m9_constX2E168Instance instance;
    m9_constX2E168Instantiate(&instance, resolveTestImports);
    printStart("const.168.wasm");
}
