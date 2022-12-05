
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func.1.h"

void test() {
    func1Instance instance;
    func1Instantiate(&instance, resolveTestImports);
    printStart("func.1.wasm");
}
