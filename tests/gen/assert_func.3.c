
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func.3.h"

void test() {
    func3Instance instance;
    func3Instantiate(&instance, resolveTestImports);
    printStart("func.3.wasm");
    func3_signatureX2DexplicitX2Dreused(&instance);
    func3_signatureX2DimplicitX2Dreused(&instance);
    func3_signatureX2DexplicitX2Dduplicate(&instance);
    func3_signatureX2DimplicitX2Dduplicate(&instance);
}
