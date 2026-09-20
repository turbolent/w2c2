
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.18.h"

void test() {
    m12_intX5FexprsX2E18Instance instance;
    m12_intX5FexprsX2E18Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.18.wasm");
}
