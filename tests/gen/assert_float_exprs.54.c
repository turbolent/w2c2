
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.54.h"

void test() {
    floatexprs54Instance instance;
    floatexprs54Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.54.wasm");
    assertEqualF32(
        floatexprs54_llvm_pr27036(&instance, 4269932491u, 14942208u),
        -10092596.0,
        "llvm_pr27036(4269932491u, 14942208u)"
    );
}
