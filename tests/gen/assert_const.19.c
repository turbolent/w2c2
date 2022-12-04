
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.19.h"

void test() {
    const19Instance instance;
    const19Instantiate(&instance, resolveTestImports);
    printStart("const.19.wasm");
}
