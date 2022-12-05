
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_data.14.h"

void test() {
    data14Instance instance;
    data14Instantiate(&instance, resolveTestImports);
    printStart("data.14.wasm");
}
