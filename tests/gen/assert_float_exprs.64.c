
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.64.h"

void test() {
    m14_floatX5FexprsX2E64Instance instance;
    m14_floatX5FexprsX2E64Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.64.wasm");
    assertEqualF64(
        m14_floatX5FexprsX2E64Export13_f64X2EkahanX5Fsum(&instance, 0u, 256u),
        4.996401743142033e+300,
        "f64.kahan_sum(0u, 256u)"
    );
    assertEqualF64(
        m14_floatX5FexprsX2E64Export13_f64X2EplainX5Fsum(&instance, 0u, 256u),
        4.9964017432979576e+300,
        "f64.plain_sum(0u, 256u)"
    );
}
