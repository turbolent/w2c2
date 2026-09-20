
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.14.h"

void test() {
    m14_floatX5FexprsX2E14Instance instance;
    m14_floatX5FexprsX2E14Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.14.wasm");
}
