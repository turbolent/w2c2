
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_select.26.h"

void test() {
    m9_selectX2E26Instance instance;
    m9_selectX2E26Instantiate(&instance, resolveTestImports);
    printStart("select.26.wasm");
}
