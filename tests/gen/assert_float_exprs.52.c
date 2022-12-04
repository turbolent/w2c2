
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.52.h"

void test() {
    floatexprs52Instance instance;
    floatexprs52Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.52.wasm");
    assertEqualF32(
        floatexprs52_llvmX5Fpr27036(&instance, 4269932491u, 14942208u),
        -10092596.0,
        "llvm_pr27036(4269932491u, 14942208u)"
    );
}
