
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.7.h"

void test() {
    m11_intX5FexprsX2E7Instance instance;
    m11_intX5FexprsX2E7Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.7.wasm");
}
