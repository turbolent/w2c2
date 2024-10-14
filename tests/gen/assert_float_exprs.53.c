
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.53.h"

void test() {
    floatexprs53Instance instance;
    floatexprs53Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.53.wasm");
    assertEqualF32(
        floatexprs53_llvm_pr27153(&instance, 33554434u),
        25165824.0,
        "llvm_pr27153(33554434u)"
    );
}
