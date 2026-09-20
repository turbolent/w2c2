
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.6.h"

void test() {
    m13_floatX5FexprsX2E6Instance instance;
    m13_floatX5FexprsX2E6Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.6.wasm");
}
