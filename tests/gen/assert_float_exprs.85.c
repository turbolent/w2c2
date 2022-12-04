
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.85.h"

void test() {
    floatexprs85Instance instance;
    floatexprs85Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.85.wasm");
    assertEqualF32(
        floatexprs85_f32X2Eepsilon(&instance),
        1.1920928955078125e-07,
        "f32.epsilon()"
    );
    assertEqualF64(
        floatexprs85_f64X2Eepsilon(&instance),
        2.220446049250313e-16,
        "f64.epsilon()"
    );
}
