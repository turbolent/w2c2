
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.90.h"

void test() {
    floatexprs90Instance instance;
    floatexprs90Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.90.wasm");
    assertEqualF64(
        floatexprs90_dot_product_example(&instance, 32000000.0, 1.0, -1.0, 80000000.0, 40000000.0, 1.0, -1.0, -16000000.0),
        2.0,
        "dot_product_example(32000000.0, 1.0, -1.0, 80000000.0, 40000000.0, 1.0, -1.0, -16000000.0)"
    );
    assertEqualF64(
        floatexprs90_with_binary_sum_collapse(&instance, 32000000.0, 1.0, -1.0, 80000000.0, 40000000.0, 1.0, -1.0, -16000000.0),
        2.0,
        "with_binary_sum_collapse(32000000.0, 1.0, -1.0, 80000000.0, 40000000.0, 1.0, -1.0, -16000000.0)"
    );
}
