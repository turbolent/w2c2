
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_select.26.h"

void test() {
    select26Instance instance;
    select26Instantiate(&instance, resolveTestImports);
    printStart("select.26.wasm");
}
