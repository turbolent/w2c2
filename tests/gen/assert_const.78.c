
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.78.h"

void test() {
    const78Instance instance;
    const78Instantiate(&instance, resolveTestImports);
    printStart("const.78.wasm");
}
