
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.50.h"

void test() {
    floatexprs50Instance instance;
    floatexprs50Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.50.wasm");
    assertEqualF32(
        floatexprs50_llvm_pr26746(&instance, -0.0),
        0.0,
        "llvm_pr26746(-0.0)"
    );
}
