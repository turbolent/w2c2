
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_call_indirect.34.h"

void test() {
    callindirect34Instance instance;
    callindirect34Instantiate(&instance, resolveTestImports);
    printStart("call_indirect.34.wasm");
}
