
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.96.h"

void test() {
    floatexprs96Instance instance;
    floatexprs96Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.96.wasm");
    assertEqualF64(
        floatexprs96_tau(&instance, 10u),
        6.283185307179583,
        "tau(10u)"
    );
    assertEqualF64(
        floatexprs96_tau(&instance, 11u),
        6.283185307179586,
        "tau(11u)"
    );
}
