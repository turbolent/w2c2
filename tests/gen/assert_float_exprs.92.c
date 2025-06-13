
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.92.h"

void test() {
    floatexprs92Instance instance;
    floatexprs92Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.92.wasm");
    assertEqualF32(
        floatexprs92_f32X2Edivision_by_small_number(&instance, 112000000.0, 100000.0, 0.0008999999845400453),
        888888.0,
        "f32.division_by_small_number(112000000.0, 100000.0, 0.0008999999845400453)"
    );
    assertEqualF64(
        floatexprs92_f64X2Edivision_by_small_number(&instance, 112000000.0, 100000.0, 0.0009),
        888888.8888888806,
        "f64.division_by_small_number(112000000.0, 100000.0, 0.0009)"
    );
}
