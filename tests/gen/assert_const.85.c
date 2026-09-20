
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.85.h"

void test() {
    m8_constX2E85Instance instance;
    m8_constX2E85Instantiate(&instance, resolveTestImports);
    printStart("const.85.wasm");
}
