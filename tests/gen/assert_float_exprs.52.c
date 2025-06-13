
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.52.h"

void test() {
    floatexprs52Instance instance;
    floatexprs52Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.52.wasm");
    assertEqualF32(
        floatexprs52_llvm_pr26746(&instance, -0.0),
        0.0,
        "llvm_pr26746(-0.0)"
    );
}
