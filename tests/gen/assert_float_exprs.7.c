
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.7.h"

void test() {
    m13_floatX5FexprsX2E7Instance instance;
    m13_floatX5FexprsX2E7Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.7.wasm");
}
