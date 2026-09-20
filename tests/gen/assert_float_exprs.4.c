
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.4.h"

void test() {
    m13_floatX5FexprsX2E4Instance instance;
    m13_floatX5FexprsX2E4Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.4.wasm");
}
