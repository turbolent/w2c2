
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.62.h"

void test() {
    floatexprs62Instance instance;
    floatexprs62Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.62.wasm");
    assertEqualF64(
        floatexprs62_f64X2EkahanX5Fsum(&instance, 0u, 256u),
        4.996401743142033e+300,
        "f64.kahan_sum(0u, 256u)"
    );
    assertEqualF64(
        floatexprs62_f64X2EplainX5Fsum(&instance, 0u, 256u),
        4.9964017432979576e+300,
        "f64.plain_sum(0u, 256u)"
    );
}
