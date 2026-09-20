
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.10.h"

void test() {
    m14_floatX5FexprsX2E10Instance instance;
    m14_floatX5FexprsX2E10Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.10.wasm");
}
