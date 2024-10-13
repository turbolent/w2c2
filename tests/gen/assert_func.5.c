
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_func.5.h"

void test() {
    func5Instance instance;
    func5Instantiate(&instance, resolveTestImports);
    printStart("func.5.wasm");
    func5_signatureX2DexplicitX2Dreused(&instance);
    func5_signatureX2DimplicitX2Dreused(&instance);
    func5_signatureX2DexplicitX2Dduplicate(&instance);
    func5_signatureX2DimplicitX2Dduplicate(&instance);
}
