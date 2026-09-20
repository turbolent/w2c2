
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.9.h"

void test() {
    m13_floatX5FexprsX2E9Instance instance;
    m13_floatX5FexprsX2E9Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.9.wasm");
}
