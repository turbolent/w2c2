
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.12.h"

void test() {
    m14_floatX5FexprsX2E12Instance instance;
    m14_floatX5FexprsX2E12Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.12.wasm");
}
