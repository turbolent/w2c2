
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_type.0.h"

void test() {
    m6_typeX2E0Instance instance;
    m6_typeX2E0Instantiate(&instance, resolveTestImports);
    printStart("type.0.wasm");
}
